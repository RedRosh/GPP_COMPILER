//* INIT
void init();

//* LOG ERROR
void logError();
void logCurrentToken();
//* COLORS
void red();
void yellow();
void green();
void blue();
void reset();

//* LEXER
void lexer_get_next_token();
//* TOKEN
TOKEN *token_init(int type, char *value);
