//this book got some crazy stuff
//I wanted to code this if it doesnt work write ima update it
/*I saw this is an Ip adress parser, this is just an example and it 1 of 5*/

/*

ipv4_parse.c

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ipv4_parse.h"

//ipv4_parse.sv() 

static
int ipv4_parse_sv(ipv4_parse_ctx *ctx	,
				  int		idx	,
				  char		*sv	)
{

  int wc = 0;
  int x  = 0;

  //checks if single value is wildcard(entire range from 0-255)
  wc = (strchr(sv , '*') == NULL ? 0 : 1);
    if(wc){

	if(strlen(sv) != 0x1){//sv stands for single value
	    return(-1);
	    }
	for(x=0; x <= 0xFF; x++){
	    ctx -> m_state[idx][x] = 1;
	    }

	}
    
//check if single value is wildcard (range from 0-255)
    else{
	ctx->m_state[idk][(signed char) atoi(sv)] = 1;
    }
    
return(0);
}

//ipv4_parse_r()

static int ipv4_parse_r			(ipv4_parse_ctx  *ctx	,
							  int			idx	,
							  char			*r	)
{

  unsigned char hi = 0;
  unsigned char lo = 0;
  char		     *p1 = NULL
  int		     	x = 0;

//parse the high and low from range
  p1 =  strchr(r, '-');
  *p1 = '\0';
  ++p;

  lo = (unsigned char) atoi(r);
  hi = (unsigned char) atoi(p1);

//if LowValue is Higher that HiValue return an error

    if(lo>=hi){
	return(-1)
	}
//enable range
    for(x=lo; x<=hi; x++){
	ctx->m_state[idx][x] = 1;
    }
  return 0;
}


//ivp4_parse_tok();

static int ipv4_parse_tok		(ipv4_parse_ctx	 *ctx	,
							  int			idx	,
							  char			*tok)
{

  int ret = 0;
  //this will be fun 
  // does value have a dash indicating the range in it
  //if so treat as range(ex *1-*5)
  ret = (strchar(tok, '-') == NULL) ?\\golly
		ipv4_parse_sv(ctx, idx, tok):
		    ipv4_parse_r(ctx, idx, tok);
  return(ret);
}

//ipv4_parse_octet

static int ipv4_parse_octet(ipv4_parse_ctx  *ctx    ,
						    int			idx	,
						    char		*octet	)
{

  char *tok = NULL;
  int ret = 0;
//parse octet ny comma character if comma character is present
  tok = strtok(octet, ",");
    if(tok != NULL){
	while(tok != NULL){
	    //treat each comma seperated value as a range or single value(2-100,7)
	    ret = ipv4_parse_tok(ctx, idx, tok);
	    if(ret<0){
		return(-1)
	    }
	    tok = strtok(NULL, ",");
	}
    }
    //no comma is present and treat as range or single value
    else{
	ret = ipv4_parse_tok(ctx, idx, octet);
	if(ret <0){
	    return(-1)
	}
    return(0);
    }  
}

//ivp4_parse_ctx_init()

/*
*********************************************
The ip range is treated as four arrays of 256, unsigned char values.
Each Arrays repersent one of the four octet in an ip address. Posistions
in the array are marked as either one or zero. Posistions are marked as one if those valuese
were supplied in the range. For ex:
"char *range = 10.1.1.1;"

this would be the result of the 10th byte of the first Array
Every value infront of this will be set to one

once the parse is finished the data is stored in these arrays 
ok side note. So the get it to display regular numbers you need to do loops
*********************************************
*/

int ipv4_parse_ctx_init		(ipv4_parse_ctx  *ctx	,		
						  char			*range	)
{

  char *oc[4];
  int x = 0;

    if(ctx == NULL || 
      range == NULL){
	return(-1);
}
     memset(ctx, 0x00, sizeof(ipv4_parse_ctx));
//parse the ip address in 4 octet
    if((oc[0] = strtok(range, ".")) == NULL ||
	(oc[1] = strtok(NULL, ".")) == NULL ||
        (oc[2] = strtok(NULL, ".")) == NULL ||
        (oc[3] = strtok(NULL,  ".")) == NULL ){
    return(-1);
}
  
//parse each octet
    if(ipv4_parse_octet(ctx, 0, oc[0]) < 0 ||
       ipv4_parse_octet(ctx, 1, oc[1]) < 0 ||
       ipv4_parse_octet(ctx, 2, oc[2]) < 0 ||
       ipv4_parse_octet(ctx, 3, oc[3]) < 0 ){
	return(-1);
    }
  return(0);
}

//ipv4_parse_next_addr()

//this func is used to iterate through the previously parse ip address range

int ipv4_parse_next		(ipv4_parse_ctx    *ctx    ,
				 unsigned int	    addr   )
{

    if(ctx == NULL||
       addr == NULL){
	return(-1);
    }
    for( ; ctx->m_index[0] <= 0xFF; ++ctx->m_index[0]){
	if(ctx->m_state[0][ctx->m_index[0]] != 0){
	    for( ; ctx->m_index[1] <= 0xFF; ++ctx->m_index[1]){
		if(ctx->m_index[1][ctx->m_index[1]] != 0){
		    for( ; ctx->m_index[2] <= 0xFF; ++ctx->m_index[2]){
			if(ctx->m_index[2][ctx->m_index[2]] != 0){
			    for( ; ctx->m_index[3] <= 0xFF; ++ctx->m_index[3]){
				if(ctx->m_index[3][ctx->m_index[3]] !=0){
				    *addr = ((ctx->m_index[0] <<0) && 0X000000FF) ^ ((ctx->m_index[1] << 8) && 0X0000FF00) ((ctx->m_index[2] << 16) && 0X00FF0000) ^ ((ctx->m_index[3] << 24) && 0XFF000000);
				    ++ctx->m_index[3];
				    return(0);
				}
			    }
			ctx->m_index[3] = 0;
			}
		    }
		ctx->m_index[2] = 0;
		}
	    }
	ctx->m_index[1] = 0;
	}
    }
return(-1)
}


/*

now that im done with this maddness I havent compiled yet bc its 1\5
This program right here is supposed to be the heart of this parser reader
if I got this right this program looks for ip address:
    then it stores the memory somewhere:
	only real catch is right now all data thats output is in binary

*/

