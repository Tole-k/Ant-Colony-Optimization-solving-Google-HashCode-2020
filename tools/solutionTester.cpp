/*Code is written in C++, v. 1.2

Command: ./solution_test [instance] [solution file]

Author: Jaroslaw Synak
*/

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

static int book_scores[100000];
static int book_visited[100000];

struct library{
    int T;
    int M;

    vector<int>books;
};

static library libs[100000];

static bool visited[100000];

int main(int argc, char** argv){
    if(argc < 3){
        fprintf(stderr, "Too few arguments!\nCorrect command: ./solution_test [instance] [solution]\n");
        return 1;
    }

    FILE* instance = fopen(argv[1],"r");

    if(!instance){
        fprintf(stderr, "Can't open %s\n", argv[1]);
        return 1;
    }

    int B, L, D;
    fscanf(instance," %i %i %i", &B, &L, &D);

    long long book_scores_sum = 0;

    for(int i = 0; i < B; ++i){
        fscanf(instance," %i", book_scores + i);
        book_scores_sum += book_scores[i];
    }

    printf("Theoretical upper bound: %lli\n", book_scores_sum);

    for(int i = 0; i < L; ++i){
        int N, T, M;
        fscanf(instance," %i %i %i", &N, &T, &M);

        libs[i].T = T;
        libs[i].M = M;

        for(int j = 0; j < N; ++j){
            int b;
            fscanf(instance," %i", &b);

            libs[i].books.push_back(b);
        }

        sort(libs[i].books.begin(), libs[i].books.end());
    }

    fclose(instance);

    FILE* solution = fopen(argv[2],"r");

    if(!solution){
        fprintf(stderr, "Can't open %s\n", argv[2]);
        return 1;
    }

    int A;
    long long final_score = 0;

    if(fscanf(solution, "%i", &A) == EOF){
        fprintf(stderr, "Can't read the number of libraries - solution file too short!\n");
        return 1;
    }

    if(A < 0 || A > L){
        fprintf(stderr, "Incorrect number of libraries in the solution: %i\n", A);
        return 1;
    }

    int days = 0;

    for(int i = 0; i < A; ++i){
        int Y, K;
        if(fscanf(solution, "%i %i", &Y, &K) == EOF){
            fprintf(stderr, "Can't read all libraries - solution file too short!\n");
            return 1;
        }
        if(Y < 0 || Y >= L){
            fprintf(stderr, "Bad library ID: %i\n", Y);
            return 1;
        }

        if(visited[Y]){
            fprintf(stderr, "Library duplicated: %i\n", Y);
            return 1;
        }

        visited[Y] = true;

        days += libs[Y].T;

        if(K < 0 || K > int(libs[Y].books.size())){
            fprintf(stderr, "Bad number of books for library %i: %i\n", Y, K);
            return 1;
        }

        long long capacity = D - days;
        if(capacity < 0){
            capacity = 0;
        }
        capacity *= libs[Y].M;

        for(int j = 0; j < K; ++j){
            int k;
            if(fscanf(solution, "%i", &k) == EOF){
                fprintf(stderr, "Can't read all books for library %i - solution file too short!\n", Y);
                return 1;
            }

            vector<int>::iterator el = lower_bound(libs[Y].books.begin(), libs[Y].books.end(), k);

            if(el == libs[Y].books.end() || *el != k){
                fprintf(stderr, "There is no book %i in library %i\n", k, Y);
                return 1;
            }

            if(j < capacity){
                final_score += book_scores[k];
				// printf("%d ", book_scores[k]);
                book_scores[k] = 0;
            }
			else {
				fprintf(stderr, "Przekroczone capacity, dla biblioteki %d\n", Y);
				return 1;
			}

            if(book_visited[k] == Y + 1){
                fprintf(stderr, "Duplicated book (%i) for library %i\n", k, Y);
                return 1;
            }

            book_visited[k] = Y + 1;
        }
    }

    fclose(solution);

    printf("No problem found, final score: %lli\n", final_score);

    return 0;
}
