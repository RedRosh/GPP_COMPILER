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
void logCurrentOperation(OPERATION *operation);
void logOperationNeedParams(int operation_type);
//* WIDGETS
void widget_init();
void widget_clean();
WIDGET *getTheCurrentWidget();
WIDGET *getWidgetById(char *widget_id);

//* SEMANTIC
void addWidgetToList();
void getAllWidgets();
void getAllOperations();
void addOperationToList();
void init_sym();

//* GTK
void show_widget(GtkWidget *gtk_widget);
void launch_gtk();
void convert_widget_to_gtk_widget();
void getAllGtkWidget();
void executeQuery();
//* OPERATION
void operation_init();
void clean_operation();
void set_operation_type();
void set_operation_id(char *widget_id);
void set_query_params(char *query);
void check_operation();
void set_position_params(int x, int y);
void set_sleep_params(int sleep);
OPERATION *getTheCurrentOperation();
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
