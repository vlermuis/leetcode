#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// Structure representing the sensor's message frame - as described in the problem statement.
typedef struct message_frame {
	uint8_t sync[2];    // 2 sync bytes (0x33 + 0xCC)
	uint8_t sequence;   // 1-byte message sequence number
	uint32_t timestamp; // 4-byte timestamp
	uint8_t state;      // 1-byte event state
	uint8_t checksum;   // 1-byte checksum of the above fields.
} message_frame_t;

// Forward declaration of a function that computes the checksum for a complete message 
// frame.  The result is returned as an 8-bit unsigned integer.
// [in] frame -- pointer to a complete message frame 
static uint8_t compute_frame_checksum(const message_frame_t* frame);

// Forward declaration of a function that processes a single byte of stream data, 
// and inserts it into the timestamp of a message frame.  This will generate a 
// correct timestamp when called consecutively on the 4 adjacent bytes of a stream 
// that make up a frame's timestamp.
//
// [in/out] frame -- pointer to an in-progress message frame
// [in] stream_byte -- byte to inject into the frame's timestamp field
static void compute_frame_timestamp(message_frame_t* frame, uint8_t stream_byte);

// Forward declaration of the function to display properly decoded frame data.
// This function is to be called by the user whenever a correctly formatted data
// frame is encountered.
// [in] frame -- pointer to a complete message frame 
static void print_sensor_data(const message_frame_t* frame);


#define TR_IDLE             (0)
#define TR_IN_PROGRESS      (1)
#define MSG0BYTE            (0xCC)
#define MSG1BYTE            (0x33)

#define MSGCHECKSUMPOS      (0x08)
#define MSGSIZE             (9)

#define OK                  (0)
#define ERROR               (-1)

// Provided to user as skeleton
typedef struct { 
	message_frame_t frame;
    int state; //0 - idle(finished processing); 1 - start receiving frame(not finished)
    int bytes_received;    // keep temporaly 
    int idx;    // current byte proccesing from the stream 
    //! ToDo: Add data elements capable of preserving the sensor's data stream
	//! state across calls to process_sensor_data_stream()
} stream_context_t;

static uint8_t msg_buffer[MSGSIZE] = {0};// 
static void reset_stream_context(stream_context_t* context)
{
   	//! ToDo: Implement this function to reset the stream's state.
    memset((void*)&msg_buffer, 0, MSGSIZE);
    memset((void*)&context->frame, 0, sizeof(message_frame_t));
    context->bytes_received = 0;
    context->state = TR_IDLE;
    context->idx = 0;
    
}

int check_data(const uint8_t* data, stream_context_t* context)
{
    if ((data[0] == MSG0BYTE) && (data[1] == MSG1BYTE))
    {
        message_frame_t frame;
        memcpy((void*)&frame, (void*)&data, sizeof(message_frame_t));
        uint8_t checksum = compute_frame_checksum(&frame);
        if (checksum == data[MSGCHECKSUMPOS])
        {// we've got a correct message
            print_sensor_data(&frame);
            memcpy((void*)&context->frame, (void*)&frame, sizeof(message_frame_t));
        }
    }
    else 
    {//some garbage data, to discard
        reset_stream_context(context);
        return ERROR;
    }
 
return OK;
}

// Definition provided to uesr
static void process_sensor_data_stream(const uint8_t* byte_stream, size_t num_bytes, stream_context_t* context)
{

	//! ToDo: Implement the function to process the byte stream.  Call print_sensor_data() whenever a valid 
	//! data frame has been detected
    
    //! Note: Multiple frames may be delivered in a single call to this function, and a single frame may be delivered
    //!       across 2 or more calls to this function.
    if (context->state == TR_IDLE)
    {
        while(num_bytes >= MSGSIZE) // MSGSIZE should be sizeof(message_frame_t)
        {//looks like we might have a complete message 
            int r= check_data(&byte_stream[context->idx], context);
            if (r == OK)
            {   
                context->idx += MSGSIZE;
                num_bytes -= MSGSIZE;
            }
            else 
            {
                break;
            }
        }
        /*check if we get not complete but possible correct message*/
        if ((byte_stream[0] == MSG0BYTE) && (byte_stream[1] == MSG1BYTE))
        {
            memcpy((void*)&msg_buffer, (void*)byte_stream, num_bytes);
            context->bytes_received = num_bytes;
            context->state = TR_IN_PROGRESS;
        }
    }
    else 
    {
        memcpy((void*)&msg_buffer[context->bytes_received], (void*)byte_stream, MSGSIZE - context->bytes_received);        
        int r= check_data(&msg_buffer[0], context);
    }
        context->bytes_received = 0;
        context->state = TR_IDLE;

}

// Compute the checksum for a message frame 
uint8_t compute_frame_checksum(const message_frame_t* frame)
{
	uint8_t checksum = 0;
	checksum += frame->sync[0];
	checksum += frame->sync[1];
	checksum += frame->sequence;
	checksum += (uint8_t)(frame->timestamp >> 24);
	checksum += (uint8_t)((frame->timestamp & 0x00FF0000) >> 16);
	checksum += (uint8_t)((frame->timestamp & 0x0000FF00) >> 8);
	checksum += (uint8_t)(frame->timestamp & 0x000000FF);
	checksum += frame->state;
	return checksum;
}

void compute_frame_timestamp(message_frame_t* frame, uint8_t stream_byte)
{
	frame->timestamp >>= 8; 
	frame->timestamp |= ((uint32_t)stream_byte) << 24;
}

void print_sensor_data(const message_frame_t* frame)
{
	printf("seq=%u, timestamp=%u, state=%u\n", frame->sequence, frame->timestamp, frame->state);
}

int main(void)
{
	stream_context_t context = {0};	
	reset_stream_context(&context);

	// The sensor's byte stream is broken into fragments, which are reported to this service via 
    // standard input for the purpose of this challenge.
    //
    // Message fragments contain an integer representing the number of bytes received from the sensor,
    // followed by a series of hex bytes containing the raw data from the sensor as described in the 
    // problem statement.  
    //
    // The data stream / test case is terminated when a fragment length <= 0 is read from standard input.
    
	int num_bytes_in_fragment = 0;
	scanf("%d", &num_bytes_in_fragment);	
	
	while (num_bytes_in_fragment > 0) {
		uint8_t* fragment = (uint8_t*)malloc(num_bytes_in_fragment);
		
		for (int i = 0; i < num_bytes_in_fragment; i++) {
			unsigned int value;
			scanf(" 0x%02X", &value);
			fragment[i] = (uint8_t)value;
		}
				
		process_sensor_data_stream(fragment, num_bytes_in_fragment, &context);
		free(fragment);
		scanf("%d", &num_bytes_in_fragment);	
	}
	return 0;	
}
