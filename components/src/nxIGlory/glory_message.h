#ifndef __GLORY_MESSAGE_H__
#define __GLORY_MESSAGE_H__

typedef enum {
	message_none = 0,
	message_margin,
	message_char,
} MessageType;

struct lexer_message_base {
	MessageType message_type;
};

struct lexer_message_margin {
	struct lexer_message_base base;
	int    margin_number;
	int    edit_position;
};

struct lexer_message_char {
	struct lexer_message_base base;
	char   added_char;
};

typedef union {
	struct lexer_message_margin __margin;
	struct lexer_message_char   __char;
} LexerMessage;

#endif /* __GLORY_MESSAGE_H__ */