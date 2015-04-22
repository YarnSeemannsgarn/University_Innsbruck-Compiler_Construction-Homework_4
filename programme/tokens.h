#ifndef TOKENS_H
#define TOKENS_H

enum Tokens{
  /* Keywords */
  PROGRAM,
  VAR,
  INTEGER,
  ARRAY,
  OF,
  REAL,
  BOOLEAN,
  _BEGIN, // BEGIN is already a builtin keyword
  WHILE,
  DO,
  IF,
  THEN,
  ELSE,
  END,
  FOR,
  TO,
  DOWNTO,
  CONST,
  READ,
  WRITE,
  DIV,
  MOD,
  AND,
  OR,
  TRUE,
  FALSE,
  NOT,

  /* Special symbols */
  SEMICOLON,
  COMMA,
  ASSIGNMENT,
  COLON,
  LEFT_SQUARE_BRACKET,
  RIGHT_SQUARE_BRACKET,
  DOT_DOT,
  DOT,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  STAR,
  SLASH,
  PLUS,
  MINUS,
  UNEQUAL,
  LESS_THAN,
  GREATER_THAN,
  GREATER_EQUAL_THAN,
  LESS_EQUAL_THAN,
  EQUAL,
  STRING,

  /* Numbers */
  NUMBER,

  /* Identifiers */
  ID,

  /* EOF */
  _EOF
};

static inline char *stringFromToken(enum Tokens t)
{
  static char *strings[] = { 
  "PROGRAM", 
  "VAR", 
  "INTEGER", 
  "ARRAY", 
  "OF", 
  "REAL", 
  "BOOLEAN", 
  "BEGIN", 
  "WHILE", 
  "DO", 
  "IF", 
  "THEN", 
  "ELSE", 
  "END", 
  "FOR", 
  "TO", 
  "DOWNTO", 
  "CONST", 
  "READ", 
  "WRITE", 
  "DIV", 
  "MOD",
  "AND",
  "OR",
  "TRUE",
  "FALSE",
  "NOT",
  "SEMICOLON",
  "COMMA",
  "ASSIGNMENT",
  "COLON",
  "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET",
  "DOT_DOT",
  "DOT",
  "LEFT_BRACKET",
  "RIGHT_BRACKET",
  "STAR",
  "SLASH",
  "PLUS",
  "MINUS",
  "UNEQUAL",
  "LESS_THAN",
  "GREATER_THAN",
  "GREATER_EQUAL_THAN",
  "LESS_EQUAL_THAN",
  "EQUAL",
  "STRING",
  "NUMBER",
  "ID",
  "_EOF"
  };

  return strings[t];
}

#endif
