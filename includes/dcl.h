//* INIT
void init();

//* LOG ERROR
void logError();
void logCurrentToken();
void log_parser_unexpected_token(int token_type);

//* COLORS
void red();
void yellow();
void green();
void blue();
void reset();

//* LEXER
void lexer_get_next_token();

//* PARSER
void parser_parse();

//* TOKEN
TOKEN *token_init(int type, char *value);
