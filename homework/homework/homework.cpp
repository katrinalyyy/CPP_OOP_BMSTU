#include <conio.h>

bool is_equal(char* s1, char* s2, int len1, int len2) {
    if (len1 != len2)
        return false;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

void copy(char* s, char* source, int len) {
    for (int i = 0; i < len; i++) {
        s[i] = source[i];
    }
}

bool is_alphabet_prefix(char* word, int len) {
    for (int i = 0; i < len; i++) {
        if (word[i] != 'z' - (len - 1 - i)) {
            return false;
        }
    }
    return true;
}


void work(int ind, char* s) {
    char words[100][100];
    int words_len[100];
    int word_ind = 0, cur_word_ind = 0;
    char cur_word[100];
    for (int i = 0; i < ind; i++) {
        if (s[i] == ' ') {
            if (cur_word_ind > 0) {
                copy(words[word_ind], cur_word, cur_word_ind);
                words_len[word_ind++] = cur_word_ind;
                cur_word_ind = 0;
            }
        }
        else {
            cur_word[cur_word_ind++] = s[i];
        }
    }
    if (cur_word_ind > 0) {
        copy(words[word_ind], cur_word, cur_word_ind);
        words_len[word_ind++] = cur_word_ind;
    }
    for (int i = 0; i < word_ind - 1; i++) {
        if (is_alphabet_prefix(words[i], words_len[i]) && !is_equal(words[i], words[word_ind - 1], words_len[i], words_len[word_ind - 1])) {
            for (int j = 0; j < words_len[i]; j++) {
                _putch(words[i][j]);
            }
            _putch(' ');
        }
    }
}


int main() {
    char c;
    c = _getch();
    char s[1000];
    int ind = 0;
    while (c != '.') {
        if ((c >= 'a' && c <= 'z') || (c == ' ')) {
            s[ind++] = c;
            _putch(c);
        }
        if ((c == 8) && (ind > 0)) {
            _putch(c);
            _putch(' ');
            _putch(c);
            s[ind--] = ' ';
        }
        c = _getch();
    }
    _putch('.');
    _putch('\n');
    work(ind, s);
    return 0;
}