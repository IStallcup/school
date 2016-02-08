struct game {
	char **board;
	int r, c, p;
	char p1;
	char p2;
};

int run_main(char *argv[]);
void print_board(game *);
bool is_valid_arguments(char *info[]);
void set_game_info(game *, char *info[]);
char** create_table(int, int);
void play_game(game *);
bool check_winner(game);
void delete_table(game *);
bool check_rows(game *, int);
bool check_cols(game *, int);
bool check_diag(game *, int);