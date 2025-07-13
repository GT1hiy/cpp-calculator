#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    input_number_ = '0';
    ui->l_result->setText(input_number_);
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmb_controller_currentIndexChanged(int index)
{
    static const std::map<QString, ControllerType> controller_map {
        {"double", ControllerType::DOUBLE},
        {"float", ControllerType::FLOAT},
        {"int", ControllerType::INT},
        {"uint8_t", ControllerType::UINT8_T},
        {"int64_t", ControllerType::INT64_T},
        {"size_t", ControllerType::SIZE_T},
        {"Rational", ControllerType::RATIONAL}
    };

    auto type = ui->cmb_controller->currentText();
    auto it = controller_map.find(type);
    if (it != controller_map.end() && callback_controller_) {
        callback_controller_(it->second);
    }
}

void MainWindow::on_btn_div_clicked()
{
    if (callback_process_operation_key_) {
        callback_process_operation_key_(Operation::DIVISION);
    }
}

void MainWindow::on_btn_mult_clicked()
{
    if (callback_process_operation_key_) {
        callback_process_operation_key_(Operation::MULTIPLICATION);
    }
}

void MainWindow::on_btn_minus_clicked()
{
    if (callback_process_operation_key_) {
        callback_process_operation_key_(Operation::SUBTRACTION);
    }
}

void MainWindow::on_btn_plus_clicked()
{
    if (callback_process_operation_key_) {
        callback_process_operation_key_(Operation::ADDITION);
    }
}

void MainWindow::on_btn_pow_clicked()
{
    if (callback_process_operation_key_) {
        callback_process_operation_key_(Operation::POWER);
    }
}

void MainWindow::on_btn_count_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::EQUALS);
    }
}

void MainWindow::on_btn_mem_clear_clicked()
{
    memory_saved_ = false;
    ui->l_memory->setText("");
}

void MainWindow::on_btn_mem_get_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::MEM_LOAD);
    }
}

void MainWindow::on_btn_mem_save_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::MEM_SAVE);
    }
}

void MainWindow::on_btn_clear_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::CLEAR);
    }
}

void MainWindow::on_btn_reverse_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::PLUS_MINUS);
    }
}

void MainWindow::on_btn_0_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(0);
    }
}

void MainWindow::on_btn_1_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(1);
    }
}

void MainWindow::on_btn_2_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(2);
    }
}

void MainWindow::on_btn_3_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(3);
    }
}

void MainWindow::on_btn_4_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(4);
    }
}

void MainWindow::on_btn_5_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(5);
    }
}

void MainWindow::on_btn_6_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(6);
    }
}

void MainWindow::on_btn_7_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(7);
    }
}

void MainWindow::on_btn_8_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(8);
    }
}

void MainWindow::on_btn_9_clicked()
{
    if (callback_digit_key_) {
        callback_digit_key_(9);
    }
}

void MainWindow::on_tb_extra_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::EXTRA_KEY);
    }
}

void MainWindow::on_btn_backspace_clicked()
{
    if (callback_process_control_key_) {
        callback_process_control_key_(ControlKey::BACKSPACE);
    }
}

void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key == std::nullopt) {
        ui->tb_extra->hide();
        return;
    }

    ui->tb_extra->setText(QString::fromStdString(key.value()));
    ui->tb_extra->show();
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    callback_digit_key_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    callback_process_operation_key_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    callback_process_control_key_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    callback_controller_ = cb;
}
