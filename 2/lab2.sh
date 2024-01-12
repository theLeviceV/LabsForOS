#!/bin/bash

function reading_text_file() {
    echo "Чтение содержимого текстового файла:"
    echo "input.txt"
    echo "-----------------------------------------"
    cat input.txt
    echo ""
    echo "output.txt"
    echo "-----------------------------------------"
    cat output.txt
}

function adding_number() {
    echo "Добавление в каждую строку файла номер строки и запись в другой файл:"
    ./lab2
}

function file_issuance() {
    echo "Выдача в stdout имён файлов:"
    ls | grep /*.txt
}

while true; do
    clear
    echo "Выберите действие:"
    echo "1) чтение содержимого текстового файла"
    echo "2) добавление в каждую строку файла № строки и запись в другой файл"
    echo "3) выдача в stdout имён файлов"
    echo "q) Выход"
    read -p "Введите свой выбор: " choice

    case $choice in
        1) reading_text_file ;;
        2) adding_number ;;
        3) file_issuance ;;
        q) break ;;
        *) echo "Неверный выбор. Пожалуйста, попробуйте снова."
    esac

    read -p "Нажмите enter, чтобы продолжить."
done
