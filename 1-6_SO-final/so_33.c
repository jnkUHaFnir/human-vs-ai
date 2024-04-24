    #include <assert.h>
    #include <math.h>
    #include <netinet/in.h>
    #include <string.h>
    #include <stdint.h>
    #include <stdlib.h>
    
    
    static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    								'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    								'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    								'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    								'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    								'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    								'w', 'x', 'y', 'z', '0', '1', '2', '3',
    								'4', '5', '6', '7', '8', '9', '+', '/'};
    static char *decoding_table = NULL;
    static int mod_table[] = {0, 2, 1};
    
    
    char *base64_encode(const char *data,
    					size_t input_length,
    					size_t *output_length) {
    	
    	*output_length = (size_t) (4.0 * ceil((double) input_length / 3.0));
    	
    	char *encoded_data = calloc(*output_length, 0x01);
    	if (encoded_data == NULL) return NULL;
    	
    	for (int i = 0, j = 0; i < input_length;) {
    		
    		uint32_t octet_a = i < input_length ? data[i++] : 0x00;
    		uint32_t octet_b = i < input_length ? data[i++] : 0x00;
    		uint32_t octet_c = i < input_length ? data[i++] : 0x00;
    		
    		uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
    		
    		encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    		encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    		encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    		encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
    	}
    	
    	for (int i = 0; i < mod_table[input_length % 3]; i++)
    		encoded_data[*output_length - 1 - i] = '=';
    	
    	return encoded_data;
    }
    
    
    char *base64_decode(const char *data,
    					size_t input_length,
    					size_t *output_length) {
    	
    	if (decoding_table == NULL) build_decoding_table();
    	
    	assert(input_length % 4 == 0);
    	
    	*output_length = input_length / 4 * 3;
    	if (data[input_length - 1] == '=') (*output_length)--;
    	if (data[input_length - 2] == '=') (*output_length)--;
    	
    	char *decoded_data = malloc(*output_length);
    	assert(decoded_data != NULL);
    	
    	for (int i = 0, j = 0; i < input_length;) {
    		
    		uint32_t sextet_a = data[i] == '=' ? 0 : decoding_table[data[i++]];
    		uint32_t sextet_b = data[i] == '=' ? 0 : decoding_table[data[i++]];
    		uint32_t sextet_c = data[i] == '=' ? 0 : decoding_table[data[i++]];
    		uint32_t sextet_d = data[i] == '=' ? 0 : decoding_table[data[i++]];
    		
    		uint32_t triple = 0;
    		triple += sextet_a << 3 * 6;
    		triple += sextet_b << 2 * 6;
    		triple += sextet_c << 1 * 6;
    		triple += sextet_d << 0 * 6;
    		
    		if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
    		if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
    		if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
    		
    		if (sextet_a == 0 || sextet_b == 0 || sextet_c == 0 || sextet_d == 0)
    			break;
    	}
    	
    	return decoded_data;
    }
    
    
    void build_decoding_table() {
    	
    	decoding_table = malloc(256);
    	memset(decoding_table, -1, 256);
    	
    	for (int i = 0; i < 0x40; i++)
    		decoding_table[encoding_table[i]] = i;
    }
    
    
    void base64_cleanup() {
    	free(decoding_table);
    }