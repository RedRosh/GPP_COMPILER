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
void logCurrentWidget(WIDGET *widget);
void logSemantic(char *message);
void logPropertiesStringSemantic(char *prop, char *attribute);
void logPropertiesIntegerSemantic(char *prop, int attribute);
void logSemanticError(char *message);
void logPropDoesntBelongToWidget(int token_prop, int widget_type);

//* WIDGETS
void widget_init();
void widget_clean();
WIDGET *getTheCurrentWidget();

//* SEMANTIC
void addWidgetToList();
void getAllWidgets();
void init_sym();

//* GTK
void show_widget(GtkWidget *gtk_widget);
void launch_gtk();
void convert_widget_to_gtk_widget();
void getAllGtkWidget();
//* COLORS
void red();
void yellow();
void green();
void blue();
void cyan();
void reset();

//* LEXER
void lexer_get_next_token();

//* PARSER
void parser_parse();

//* TOKEN
TOKEN *token_init(int type, char *value);
