#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

TOKEN *token_init(int type, char *value)
{
	TOKEN *token = calloc(1, sizeof(TOKEN));
	token->type = type;
	token->value = value;
	return token;
}
