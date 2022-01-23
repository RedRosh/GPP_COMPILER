//* INIT
void init();

//* LOG ERROR
void logError();
void logCurrentToken();
void log_parser_unexpected_token(int token_type);
void log_parser_unexpected_token_attribute();
void log_parser_unexpected_token_prop();
void logErrorParser(char *message);
void logSuccessParser(char *message);

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
