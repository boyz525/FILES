//created by alexander malahov
//var 2


#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

using namespace std;

int main () {
    // Открываем файл архива в режиме бинарного чтения
    ifstream file("files.zip", ios::binary);
    if (!file.is_open()) {
        cout << "Failed to open file\n";
    }

    // Считываем сигнатуру заголовка local file header
    int signature;
    file.read((char*)&signature, sizeof(signature));
    if (signature != 0x04034b50) {
        cout << "Invalid local file header signature\n";
    }

    // Считываем размер имени файла и имя файла
    int fileNameLength;
    file.read((char*)&fileNameLength, sizeof(fileNameLength));
    string fileName(fileNameLength, ' ');
    file.read(&fileName[0], fileNameLength);

    // Считываем размер несжатых данных
    int uncompressedSize;
    file.read((char*)&uncompressedSize, sizeof(uncompressedSize));

    cout << "File name: " << fileName << endl;
    cout << "Uncompressed size: " << uncompressedSize << " bytes" << endl;

    // Закрываем файл архива
    file.close();

    return 0;
}


//3b

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    double x0, xn, step, c;
    
    // Открываем файл для чтения
    ifstream in_file("in.txt");
    
    if (in_file.is_open()) {
        // Считываем данные из файла
        in_file >> x0 >> xn >> step >> c;
    } else {
        // Если файл не удалось открытm выводим сообщение
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }
    // Закрываем файл
    in_file.close();
    
    // Открываем файл для записи результатов
    ofstream out_file("out.txt");
    
    if (out_file.is_open()) {
        for (double x = x0; x <= xn; x += step) {
            double y = 0.0;
            // Вычисляем функцию для каждого значения x
            for (int i = 1; i <= c; i++) {
                y += 1.0 / (i * x);
            }
            // Записываем результат в файл
            out_file << x << ", " << y << endl;
        }
        // Сообщаем о том, что файл успешно создан
        cout << "Файл успешно создан!" << endl;
    } else {
        // Если файл не удалось открыть выводим 
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }
    // Закрываем файл
    out_file.close();
    
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string surname;
    float avg_grade;
    int course;
};

int main() {

    const int NUM_STUDENTS = 3;/* Тут можно поставить любое значение, 
    но я для удобства проверки сделал 3, а тк у уже 4 утра у меня бошка вообще не варит
    ахах так что получилось че получилось я ниче лучше не придумал*/
    Student students[NUM_STUDENTS]; // Создаем массив структур для хранения информации о студентах
    
    // Вводим данные о студентах
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Введите фамилию студента " << i+1 << ": ";
        cin >> students[i].surname;
        cout << "Введите среднюю оценку студента " << i+1 << ": ";
        cin >> students[i].avg_grade;
        cout << "Введите курс студента " << i+1 << ": ";
        cin >> students[i].course;
    }
    
    // Открываем файл для записи результатов
    ofstream out_file("students.txt");
    
    if (out_file.is_open()) {
        // Записываем данные о студентах в файл
        for (int i = 0; i < NUM_STUDENTS; i++) {
            out_file << students[i].surname << endl;
            out_file << students[i].avg_grade << endl;
            out_file << students[i].course << endl;
        }
        // Сообщаем пользователю о том, что файл успешно создан
        cout << "Файл успешно создан!" << endl;
    } else {
        // Если файл не удалось открыть, выводим сообщение
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }
    // Закрываем файл
    out_file.close();
    
    return 0;
}