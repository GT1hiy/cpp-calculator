#pragma once

#include "calculator.h"
#include "enums.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    enum CalculatorState {
        NO_OPERATION,
        ADDITION,
        SUBSTRACTION,
        MULTIPLICATION,
        DIVISION,
        POWER
    };

    void SetDigitKeyCallback(std::function<void(int key)> cb);

    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);

    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);

    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

    void SetInputText(const std::string& text);

    void SetErrorText(const std::string& text);

    void SetFormulaText(const std::string& text);

    void SetMemText(const std::string& text);

    void SetExtraKey(const std::optional<std::string>& key);

private slots:

    void on_btn_div_clicked();

    void on_btn_mult_clicked();

    void on_btn_minus_clicked();

    void on_btn_plus_clicked();

    void on_btn_count_clicked();

    void on_btn_pow_clicked();

    void on_btn_mem_clear_clicked();

    void on_btn_mem_get_clicked();

    void on_btn_mem_save_clicked();

    void on_btn_clear_clicked();

    void on_btn_reverse_clicked();

    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_backspace_clicked();

    void on_cmb_controller_currentIndexChanged(int index);

    void on_tb_extra_clicked();

private:

    void AppendOrChangeInputNumber(QString input);

    void RedrawInputNumber() const;

private:
    Ui::MainWindow* ui;
    CalculatorState current_operation_ = CalculatorState::NO_OPERATION;
    QString input_number_;
    bool memory_saved_ = false;

    // callback section
    std::function<void(int)> callback_digit_key_;
    std::function<void(Operation)> callback_process_operation_key_;
    std::function<void(ControlKey)> callback_process_control_key_;
    std::function<void(ControllerType)> callback_controller_;
};

