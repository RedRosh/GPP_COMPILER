#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

static Lexer *lexer;
static int token_keyword[] = {
	TOKEN_INTERFACE,
	TOKEN_INPUTFIELD,
	TOKEN_BUTTON,
	TOKEN_LABEL,
	TOKEN_SIZE,
	TOKEN_TEXT,
	TOKEN_ID,
	TOKEN_COLOR,
	TOKEN_POSITION,
	TOKEN_BORDER,
	TOKEN_BACKGROUND,
	TOKEN_WIDTH,
	TOKEN_HEIGHT,
	TOKEN_TEXTALIGN,
	TOKEN_BEGIN,
	TOKEN_END,
	TOKEN_START,
	TOKEN_PUT,
};
static char *keyword[] = {
	"Interface",
	"InputField",
	"Button",
	"Label",
	"Size",
	"Text",
	"ID",
	"Color",
	"Position",
	"Border",
	"Background",
	"Width",
	"Height",
	"TextAlign",
	"Begin",
	"End",
	"Start",
	"Put",
};

void lexer_init()
{
	lexer = calloc(1, sizeof(Lexer));
}

void lexer_get_next_caracter()
{
	if (Putback)
	{
		lexer->c = Putback;
		Putback = 0;
		return;
	}
	lexer->c = fgetc(inFile);
	if (lexer->c == '\n')
	{
		Line++;
	}
}

void lexer_skip_whitespace()
{

	lexer_get_next_caracter();

	while (lexer->c == ' ' || lexer->c == '\n' || lexer->c == '\t' || lexer->c == '\r' || lexer->c == '\f')
	{
		lexer_get_next_caracter();
	}
}

void lexer_putback()
{
	Putback = lexer->c;
}

char *lexer_get_id()
{
	char *value = calloc(1, sizeof(char));
	value[0] = '\0';
	while (isalnum(lexer->c))
	{
		char *s = lexer_get_caracter_as_string();
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);

		lexer_get_next_caracter();
	}
	lexer_putback();
	return value;
}

char *lexer_get_caracter_as_string()
{
	char *c = calloc(2, sizeof(char));
	c[0] = lexer->c;
	c[1] = '\0';
	return c;
}

int lexer_get_int()
{
	char *value = calloc(2, sizeof(char));

	while (isdigit(lexer->c))
	{
		strcat(value, lexer_get_caracter_as_string());
		lexer_get_next_caracter();
	}
	lexer_putback();
	return atoi(value);
}

char *lexer_get_number_as_string(int number)
{
	int length = snprintf(NULL, 0, "%d", number);
	char *str = malloc(length + 1);
	snprintf(str, length + 1, "%d", number);
	return str;
}

char *lexer_get_string()
{
	lexer_get_next_caracter();

	char *value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (lexer->c != '"')
	{
		if (lexer->c == EOF)
		{
			return "____end___of______file____";
		}
		char *s = lexer_get_caracter_as_string();
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_get_next_caracter();
	}

	lexer_get_next_caracter();
	return value;
}

void lexer_get_next_token()
{

	lexer_skip_whitespace();
	switch (lexer->c)
	{
	case EOF:
	{
		Token = token_init(TOKEN_EOF, "End Of File");
		return;
	}
	case ':':
	{
		Token = token_init(TOKEN_DP, lexer_get_caracter_as_string());
		return;
	}
	case '{':
	{
		Token = token_init(TOKEN_OB, lexer_get_caracter_as_string());
		return;
	}
	case '}':
	{
		Token = token_init(TOKEN_FB, lexer_get_caracter_as_string());
		return;
	}
	case ';':
	{
		Token = token_init(TOKEN_PV, lexer_get_caracter_as_string());
		return;
	}
	case ',':
	{
		Token = token_init(TOKEN_COMMA, lexer_get_caracter_as_string());
		return;
	}
	default:
	{
		if (lexer->c == '"')
		{
			int BeginningOfString = Line;
			char *string = lexer_get_string();
			if (!strcmp(string, "____end___of______file____"))
			{
				red();
				printf("[ Lexer ] : Expected \" , the end of string that begins at %d was not found \n", BeginningOfString);
				reset();
				Token = token_init(TOKEN_EOF, "End Of File");
				return;
			}
			Token = token_init(TOKEN_STRING, string);
			return;
		}
		if (isdigit(lexer->c))
		{
			int number = lexer_get_int();
			Token = token_init(TOKEN_INTLIT, lexer_get_number_as_string(number));
			return;
		}
		if (isalpha(lexer->c))
		{
			char *identificateur = lexer_get_id();
			int length = sizeof keyword / sizeof keyword[0];
			for (int i = 0; i < length; i++)
			{
				if (!strcmp(identificateur, keyword[i]))
				{
					Token = token_init((int)token_keyword[i], identificateur);
					return;
				}
			}
			Token = token_init(TOKEN_ERREUR, identificateur);
			return;
		}
		Token = token_init(TOKEN_ERREUR, lexer_get_caracter_as_string());
		return;
	}
	}
};