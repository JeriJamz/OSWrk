//ipv4_parse.h
//so this is how to make header files
//I need to make the common.h file


#ifndef __IPV4_PARSE_H__//(1)
#define __IPV4_PARSE_H__//(2)this one

#ifdef __cplusplus
extern "C"{
#endif

typedef struct ivp4_parse_ctx{

    unsigned char m_state[4][256];
    unsigned short m_index[4];

}ipv4_parse_ctx;

//this is the init of the ipv4 parse

int ipv4_parse_ctx_init		(ivp4_parse_ctx  *ctx	,
				 char				*range	);


//this init the ivp4 parse next addr

int ipv4_parse_next		(ivp4_parse_ctx  *ctx   ,
						  unsigned int	   *addr    );

#ifdef __cplusplus
}
#endif//(2)this endif is for 

#endif //follow the numbers(1)

