#define N 5
#include <iomanip>
#include <iostream>
#include <conio.h>

void main() {
    struct point {
        int row, column;
    };
    float m[N][N];
    int i, j;
    void min(float matrix[N][N], float& mn);
    void max(float matrix[N][N], float& mx);
    void min_down_triangle(float matrix[N][N], float& mn);
    void max_down_triangle(float matrix[N][N], float& mx);
    void min_up_triangle(float matrix[N][N], float& mn);
    void max_up_triangle(float matrix[N][N], float& mx);
    void max_main_diagonal(float matrix[N][N], float& mx);
    void min_main_diagonal(float matrix[N][N], float& mn);
    void max_sub_diagonal(float matrix[N][N], float& mx);
    void min_sub_diagonal(float matrix[N][N], float& mn);
    void average(float matrix[N][N], float& avr);
    void average_down_triangle(float matrix[N][N], float& avr);
    void average_up_triangle(float matrix[N][N], float& avr);
    void sum_by_row(float matrix[N][N], float(&sum)[N]);
    void sum_by_column(float matrix[N][N], float(&sum)[N]);
    void min_by_row(float matrix[N][N], float(&mn)[N]);
    void min_by_column(float matrix[N][N], float(&mn)[N]);
    void max_by_row(float matrix[N][N], float(&mx)[N]);
    void max_by_column(float matrix[N][N], float(&mx)[N]);
    void average_by_row(float matrix[N][N], float(&avr)[N]);
    void average_by_column(float matrix[N][N], float(&avr)[N]);
    void sum_down_triangle(float matrix[N][N], float& sum);
    void sum_up_triangle(float matrix[N][N], float& sum);
    void nearest_to_average(float matrix[N][N], int& r, int& c);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) m[i][j] = rand() / 10.;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        std::cout << std::endl;
    }
    _getch();

    float result;
    float result2[N];
    int r, c;
    min(m, result);
    std::cout << "Min: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    max(m, result);
    std::cout << "Max: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    min_down_triangle(m, result);
    std::cout << "Min down triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    max_down_triangle(m, result);
    std::cout << "Max down triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    min_up_triangle(m, result);
    std::cout << "Min up triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    max_up_triangle(m, result);
    std::cout << "Max up triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    max_main_diagonal(m, result);
    std::cout << "Max main diagonal: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    min_main_diagonal(m, result);
    std::cout << "Min main diagonal: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    max_sub_diagonal(m, result);
    std::cout << "Max sub diagonal: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    min_sub_diagonal(m, result);
    std::cout << "Min sub diagonal: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    average(m, result);
    std::cout << "Average: " << result << std::setw(8) << std::setprecision(5) << std::endl;
    average_down_triangle(m, result);
    std::cout << "Average down triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    average_up_triangle(m, result);
    std::cout << "Average up triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    sum_by_row(m, result2);
    std::cout << "Sum by row: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i] << std::endl;
    }
    sum_by_column(m, result2);
    std::cout << "Sum by column: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i];
    }
    std::cout << std::endl;
    min_by_row(m, result2);
    std::cout << "Min by row: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i] << std::endl;
    }
    min_by_column(m, result2);
    std::cout << "Min by column: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i];
    }
    std::cout << std::endl;
    max_by_row(m, result2);
    std::cout << "Max by row: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i] << std::endl;
    }
    max_by_column(m, result2);
    std::cout << "Max by column: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i];
    }
    std::cout << std::endl;
    average_by_row(m, result2);
    std::cout << "Average by row: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i] << std::endl;
    }
    average_by_column(m, result2);
    std::cout << "Average by column: " << std::endl;
    for (i = 0; i < N; i++) {
        std::cout << std::setw(8) << std::setprecision(5) << result2[i];
    }
    std::cout << std::endl;
    sum_down_triangle(m, result);
    std::cout << "Sum down triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    sum_up_triangle(m, result);
    std::cout << "Sum up triangle: " << std::setw(8) << std::setprecision(5) << result << std::endl;
    nearest_to_average(m, r, c);
    std::cout << "Nearest to average: " << std::setw(8) << std::setprecision(5)
        << "matrix[" << r << "][" << c << "] = " << m[r][c] << std::endl;
}

void min(float matrix[N][N], float& mn) {
    mn = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mn > matrix[i][j]) {
                mn = matrix[i][j];
            }
        }
    }
}

void max(float matrix[N][N], float& mx) {
    mx = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mx < matrix[i][j]) {
                mx = matrix[i][j];
            }
        }
    }
}

void min_down_triangle(float matrix[N][N], float& mn) {
    mn = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (mn > matrix[i][j]) {
                mn = matrix[i][j];
            }
        }
    }
}

void max_down_triangle(float matrix[N][N], float& mx) {
    mx = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (mx < matrix[i][j]) {
                mx = matrix[i][j];
            }
        }
    }
}

void min_up_triangle(float matrix[N][N], float& mn) {
    mn = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (mn > matrix[i][j]) {
                mn = matrix[i][j];
            }
        }
    }
}

void max_up_triangle(float matrix[N][N], float& mx) {
    mx = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (mx < matrix[i][j]) {
                mx = matrix[i][j];
            }
        }
    }
}

void max_main_diagonal(float matrix[N][N], float& mx) {
    mx = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (mx < matrix[i][i]) {
            mx = matrix[i][i];
        }
    }
}

void min_main_diagonal(float matrix[N][N], float& mn) {
    mn = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (mn > matrix[i][i]) {
            mn = matrix[i][i];
        }
    }
}

void max_sub_diagonal(float matrix[N][N], float& mx) {
    mx = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (mx < matrix[i][N - i - 1]) {
            mx = matrix[i][N - i - 1];
        }
    }
}

void min_sub_diagonal(float matrix[N][N], float& mn) {
    mn = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (mn > matrix[i][N - i - 1]) {
            mn = matrix[i][N - i - 1];
        }
    }
}

void average(float matrix[N][N], float& avr) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    avr = sum / (N * N);
}

void average_down_triangle(float matrix[N][N], float& avr) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += matrix[i][j];
        }
    }
    int elem_count = N * (N - 1) / 2;
    avr = sum / float(elem_count);
}

void average_up_triangle(float matrix[N][N], float& avr) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    int elem_count = N * (N - 1) / 2;
    avr = sum / float(elem_count);
}

void sum_by_row(float matrix[N][N], float(&sum)[N]) {
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
        for (int j = 0; j < N; j++) {
            sum[i] += matrix[i][j];
        }
    }
}

void sum_by_column(float matrix[N][N], float(&sum)[N]) {
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
        for (int j = 0; j < N; j++) {
            sum[i] += matrix[j][i];
        }
    }
}

void min_by_row(float matrix[N][N], float(&mn)[N]) {
    for (int i = 0; i < N; i++) {
        mn[i] = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (mn[i] > matrix[i][j]) {
                mn[i] = matrix[i][j];
            }
        }
    }
}

void min_by_column(float matrix[N][N], float(&mn)[N]) {
    for (int i = 0; i < N; i++) {
        mn[i] = matrix[0][i];
        for (int j = 1; j < N; j++) {
            if (mn[i] > matrix[j][i]) {
                mn[i] = matrix[j][i];
            }
        }
    }
}

void max_by_row(float matrix[N][N], float(&mx)[N]) {
    for (int i = 0; i < N; i++) {
        mx[i] = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (mx[i] < matrix[i][j]) {
                mx[i] = matrix[i][j];
            }
        }
    }
}

void max_by_column(float matrix[N][N], float(&mx)[N]) {
    for (int i = 0; i < N; i++) {
        mx[i] = matrix[0][i];
        for (int j = 1; j < N; j++) {
            if (mx[i] < matrix[j][i]) {
                mx[i] = matrix[j][i];
            }
        }
    }
}

void average_by_row(float matrix[N][N], float(&avr)[N]) {
    float sum[N];
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
        for (int j = 0; j < N; j++) {
            sum[i] += matrix[i][j];
        }
        avr[i] = sum[i] / N;
    }
}

void average_by_column(float matrix[N][N], float(&avr)[N]) {
    float sum[N];
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
        for (int j = 0; j < N; j++) {
            sum[i] += matrix[j][i];
        }
        avr[i] = sum[i] / N;
    }
}

void sum_down_triangle(float matrix[N][N], float& sum) {
    sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += matrix[i][j];
        }
    }
}

void sum_up_triangle(float matrix[N][N], float& sum) {
    sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += matrix[i][j];
        }
    }
}

void nearest_to_average(float matrix[N][N], int& r, int& c) {
    float avr = 0;
    average(matrix, avr);
    float q = std::abs(avr - matrix[0][0]);
    r = 0;
    c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (std::abs(avr - matrix[i][j]) < q) {
                q = std::abs(avr - matrix[i][j]);
                r = i;
                c = j;
            }
        }
    }
}
