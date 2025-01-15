#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent, Calculator calculator)
    : QMainWindow(parent), ui(new Ui::MainWindow), calculator_{calculator} {
    ui->setupUi(this);
    ui->l_result->setText(input_number_);
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_0_clicked() {
    DoNumberInput(QChar{'0'});
}

void MainWindow::on_btn_1_clicked() {
    DoNumberInput(QChar{'1'});
}

void MainWindow::on_btn_2_clicked() {
    DoNumberInput(QChar{'2'});
}

void MainWindow::on_btn_3_clicked() {
    DoNumberInput(QChar{'3'});
}

void MainWindow::on_btn_4_clicked() {
    DoNumberInput(QChar{'4'});
}

void MainWindow::on_btn_5_clicked() {
    DoNumberInput(QChar{'5'});
}

void MainWindow::on_btn_6_clicked() {
    DoNumberInput(QChar{'6'});
}

void MainWindow::on_btn_7_clicked() {
    DoNumberInput(QChar{'7'});
}

void MainWindow::on_btn_8_clicked() {
    DoNumberInput(QChar{'8'});
}

void MainWindow::on_btn_9_clicked() {
    DoNumberInput(QChar{'9'});
}

void MainWindow::on_btn_change_sign_clicked() {
    DoChangeSignInput();

}

void MainWindow::on_btn_dot_clicked() {
    DoDotDelimeterInput();
}


void MainWindow::on_btn_clear_clicked() {
    DoClearInput();
}


void MainWindow::on_btn_delete_clicked() {
    DoDeleteInput();
}

void MainWindow::on_btn_plus_clicked() {
    DoOperationInput(OperationType::ADDITION);
}

void MainWindow::on_btn_minus_clicked() {
    DoOperationInput(OperationType::SUBTRACTION);
}


void MainWindow::on_btn_multiplicate_clicked() {
    DoOperationInput(OperationType::MULTIPLICATION);
}


void MainWindow::on_btn_divide_clicked() {
    DoOperationInput(OperationType::DIVISION);
}

void MainWindow::on_btn_power_clicked() {
    DoOperationInput(OperationType::POWER);
}

void MainWindow::on_btn_result_clicked() {
    DoShowResultInput();
}

void MainWindow::on_btn_memory_clear_clicked() {
    DoMemoryClearInput();
}

void MainWindow::on_btn_memory_store_clicked() {
    DoMemoryStoreInput();
}

void MainWindow::on_btn_memory_remember_clicked() {
    DoMemoryRemember();
}



void MainWindow::DoMemoryClearInput() {
    memory_cell_ = nan("");
    ui->l_memory->setText("");
    memory_saved_ = false;
}

void MainWindow::DoMemoryStoreInput() {
    memory_cell_ = input_number_.toDouble();
    ui->l_memory->setText("M");
    memory_saved_ = true;
    is_dot_delimeter_set_ = false;
    is_new_input_ = true;
}

void MainWindow::DoMemoryRemember() {
    if (memory_saved_) {
        input_number_ = QString::number(memory_cell_);

        ui->l_result->setText(input_number_);

        is_dot_delimeter_set_ = false;
        is_new_input_ = true;
        can_edit_ = false;
    };
}

void MainWindow::DoShowResultInput() {
    Number left_operand = active_number_;
    Number right_operand = input_number_.toDouble();
    QString formula_string;

    is_dot_delimeter_set_ = true;
    is_new_input_ = true;
    can_edit_ = false;

    if (current_operation_ == OperationType::NO_OPERATION){
        return;
    }

    CalculateResult(right_operand);
    input_number_ = QString::number(active_number_);
    formula_string = QString("%1 %2 %3 =").arg(left_operand).arg(GetOperationSign(current_operation_)).arg(right_operand);

    ui->l_formula->setText(formula_string);
    ui->l_result->setText(input_number_);

    current_operation_ = OperationType::NO_OPERATION;
}

void MainWindow::DoNumberInput(QChar ch) {
    if (is_new_input_) {
        is_dot_delimeter_set_ = false;
        input_number_ = ch;
        ui->l_result->setText(input_number_);
        is_new_input_ = false;
        can_edit_ = true;
        return;
    };

    if (input_number_.size() == 1 && input_number_.front() == '0') {
        input_number_ = ch;
    } else {
        input_number_.push_back(ch);
    }

    ui->l_result->setText(input_number_);

}

void MainWindow::DoDotDelimeterInput() {

    if (is_dot_delimeter_set_){
        return;
    }

    if (is_new_input_) {
        input_number_ = '0';
        is_dot_delimeter_set_ = false;
        is_new_input_ = false;
    }

    input_number_.push_back('.');
    is_dot_delimeter_set_ = true;
    ui->l_result->setText(input_number_);
}

void MainWindow::DoClearInput() {
    is_dot_delimeter_set_ = false;
    is_new_input_ = true;
    input_number_ = '0';
    active_number_ = 0;
    calculator_.Set(active_number_);
    ui->l_result->setText(input_number_);
    ui->l_formula->setText("");
}

void MainWindow::DoDeleteInput() {

    if ( can_edit_ ) {

        if (input_number_.back() == '.'){
            is_dot_delimeter_set_ = false;
        }
        if (input_number_.size() > 0){
            input_number_.truncate(input_number_.size() - 1);
        }
        if (input_number_.size() == 0){
            input_number_ = "0";
        }
        if (input_number_ == "-0"){
            input_number_ = "0";
        }
        if (input_number_ == "-"){
            input_number_ = "0";
        }

        ui->l_result->setText(input_number_);
    }
}

void MainWindow::DoOperationInput(OperationType operation) {
    QString formula_string;

    if (current_operation_ == OperationType::NO_OPERATION) {
        active_number_ = input_number_.toDouble();
        calculator_.Set(active_number_);
        current_operation_ = operation;
        formula_string = QString("%1 %2").arg(calculator_.GetNumber()).arg(GetOperationSign(operation));
        ui->l_formula->setText(formula_string);

        is_new_input_ = true;
        can_edit_ = false;
        is_dot_delimeter_set_ = false;

        return;
    }

    if (current_operation_ != OperationType::NO_OPERATION) {
        current_operation_ = operation;
        formula_string = QString("%1 %2").arg(active_number_).arg(GetOperationSign(operation));
        ui->l_formula->setText(formula_string);

        is_new_input_ = true;
        can_edit_ = false;
        is_dot_delimeter_set_ = false;

        return;
    };
}

QChar MainWindow::GetOperationSign(OperationType operation) const {
    QChar result;

    switch (operation) {
    case OperationType::ADDITION:
        result = QChar(0x002B);
        break;
    case OperationType::SUBTRACTION:
        result = QChar(0x2212);
        break;
    case OperationType::MULTIPLICATION:
        result = QChar(0x00D7);
        break;
    case OperationType::DIVISION:
        result = QChar(0x00F7);
        break;
    case OperationType::POWER:
        result = QChar(0x005E);
    };

    return result;
}


void MainWindow::DoChangeSignInput() {

    if (input_number_ == "0" || input_number_ == "nan") {
        return;
    }

    if (!can_edit_) {
        return;
    }

    if (input_number_.front() == '-') {
        input_number_.remove('-');
    } else {
        input_number_.push_front('-');
    }


    ui->l_result->setText(input_number_);
}

void MainWindow::CalculateResult(Number right_operand) {
    switch (current_operation_) {
    case OperationType::ADDITION:
        calculator_.Add(right_operand);
        active_number_ = calculator_.GetNumber();
        break;
    case OperationType::SUBTRACTION:
        calculator_.Add(-right_operand);
        active_number_ = calculator_.GetNumber();
        break;
    case OperationType::MULTIPLICATION:
        calculator_.Mul(right_operand);
        active_number_ = calculator_.GetNumber();
        break;
    case OperationType::DIVISION:
        calculator_.Div(right_operand);
        active_number_ = calculator_.GetNumber();
        break;
    case OperationType::POWER:
        calculator_.Pow(right_operand);
        active_number_ = calculator_.GetNumber();
    }

    return;
}

