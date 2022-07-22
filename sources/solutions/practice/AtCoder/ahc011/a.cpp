#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) do { Debug::debug(nullptr, "#" + to_string(__LINE__) + ": "); Debug::debug(__VA_ARGS__); } while(0);
#else
    #define debug(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }


constexpr int di[4] = { 0, -1, 0, 1 }, dj[4] = { -1, 0, 1, 0 };
constexpr char coms[4] = { 'L', 'U', 'R', 'D' };

random_device rd;
default_random_engine random_engine(rd());
uniform_int_distribution<int> distr_0to3(0, 3);

constexpr int TIME_LIMIT_MS = 2950;
constexpr int BASE_SCORE = 500000;

using Chip = short;

Chip inline to_chip_num(char x) {
    if('0' <= x && x <= '9') return x - '0';
    else return x - 'a' + 10;
}

inline short inverted(short com) {
    return (com + 2) % 4;
}

struct Position {
    int i; int j;
    Position() : i(0), j(0) {}
    Position(int p, int q) : i(p), j(q) {}
    inline bool operator== (Position &rhs) { return i == rhs.i && j == rhs.j; }
};

template <class T> struct Matrix : vector<vector<T>> {
    Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
    Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
};

struct Board : Matrix<Chip> {
    Board(int n) : Matrix<Chip> (n, n), n(n), t(2*n*n*n), area(n*n) {};
    int n, t, area;
    Position empty_pos;
    string history = "";
    inline bool is_out_of_board(Position *pos) {
        return pos->i < 0 || n <= pos->i || pos->j < 0 || n <= pos->j;
    }
    inline int pos_to_id(Position *pos) {
        return pos->i * n + pos->j;
    }
};

int move(Board *board, short com) {
    Position next_pos(board->empty_pos.i + di[com], board->empty_pos.j + dj[com]);
    if(board->is_out_of_board(&next_pos)) return 1;
    swap((*board)[board->empty_pos.i][board->empty_pos.j], (*board)[next_pos.i][next_pos.j]);
    board->empty_pos = next_pos;
    board->history += coms[com];
    return 0;
}

int search_max_tree_size(Board *board, Position *prev, Position *pos, vector<bool> *visited, int *length = 0) {
    const int pos_id = board->pos_to_id(pos);
    if((*visited)[pos_id]) { return 1; }
    Chip chip = (*board)[pos->i][pos->j];
    (*visited)[pos_id] = true;
    ++(*length);
    // debug(to_string(pos.i) + ", " + to_string(pos.j), " ");
    // debug(*length);
    REP(k, 4) {
        Position next_pos(pos->i + di[k], pos->j + dj[k]);
        if(next_pos == *prev) continue;
        if(board->is_out_of_board(&next_pos)) continue;
        Chip next_chip = (*board)[next_pos.i][next_pos.j];
        if(!((chip >> k & 1) && (next_chip >> inverted(k) & 1))) continue;
        int res = search_max_tree_size(board, pos, &next_pos, visited, length);
        if(res != 0) return res;
    }
    return 0;
}

int calc_score(Board *board) {
    vector<bool> visited(board->area);
    int best_tree_size = 0;
    Position dummy_pos(-1, -1);
    REP(i, board->n) REP(j, board->n) {
        if(visited[i * (board->n) + j]) continue;
        int found_max_tree_size = 0;
        Position pos(i, j);
        int res = search_max_tree_size(board, &dummy_pos, &pos, &visited, &found_max_tree_size);
        if(res != 0) continue;
        chmax(best_tree_size, found_max_tree_size);
    }
    if(best_tree_size == board->area - 1) return BASE_SCORE * 2 - BASE_SCORE * board->history.size() / board->t;
    else return BASE_SCORE * best_tree_size / (board->area - 1);
}

void modify(int tolerance, Board next_board, Board *current_best_board, int *current_best_score) {
    short prev_com_inv = -1;
    REP(j, tolerance) {
        short com = 0;
        do {
            com = distr_0to3(random_engine);
        } while(com == prev_com_inv);
        prev_com_inv = inverted(com);
        int res = move(&next_board, com);
        if(res) continue;
        const int next_score = calc_score(&next_board);
        if(*current_best_score < next_score) {
            debug(next_score);
            //debug(next_board.history);
            *current_best_board = next_board;
            current_best_board->history = regex_replace(current_best_board->history, regex("LR|RL|UD|DU"), "");
            *current_best_score = next_score;
            // *current_best_score = calc_score(current_best_board);
        }
    }
}

signed main() {
    clock_t start = clock();
    int n, t; cin >> n >> t;
    Board original_board(n);
    REP(i, n) REP(j, n) {
        char x; cin >> x;
        original_board[i][j] = to_chip_num(x);
    }
    REP(i, n) REP(j, n) {
        if(original_board[i][j] == 0) original_board.empty_pos = Position (i, j);
    }
    debug(calc_score(&original_board));
    Board final_board = original_board;
    const int original_score = calc_score(&original_board);
    int final_score = original_score;
    while((clock() - start) * 1000 < TIME_LIMIT_MS * CLOCKS_PER_SEC) {
        Board next_board = final_board, current_best_board = final_board;
        int current_best_score = final_score;
        modify(min(100UL, t - current_best_board.history.size()), next_board, &current_best_board, &current_best_score);
        if(chmax(final_score, current_best_score)) {
            final_board = current_best_board;
            debug(final_score);
        }
    }
    cout << final_board.history << endl;
    return 0;
}
