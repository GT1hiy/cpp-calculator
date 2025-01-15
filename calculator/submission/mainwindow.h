#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


enum class OperationType {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr, Calculator calculator = Calculator());
    ~MainWindow();

private slots:

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

    void on_btn_dot_clicked();

    void on_btn_clear_clicked();

    void on_btn_delete_clicked();

    void on_btn_plus_clicked();

    void on_btn_minus_clicked();

    void on_btn_multiplicate_clicked();

    void on_btn_divide_clicked();

    void on_btn_power_clicked();

    void on_btn_change_sign_clicked();

    void on_btn_result_clicked();

    void on_btn_memory_clear_clicked();

    void on_btn_memory_store_clicked();

    void on_btn_memory_remember_clicked();

private:
    Ui::MainWindow* ui;
    OperationType current_operation_ = OperationType::NO_OPERATION;
    QString input_number_ = "0";
    Calculator calculator_;
    Number active_number_ = 0;
    Number memory_cell_;
    bool memory_saved_ = false;
    bool is_dot_delimeter_set_ = false;
    bool is_new_input_ = true;
    bool can_edit_ = true;

    void DoNumberInput(QChar ch);
    void DoDeleteInput();
    void DoDotDelimeterInput();
    void DoClearInput();
    void DoOperationInput(OperationType operation);
    QChar GetOperationSign(OperationType operation) const;
    void UpdateFormulaText();
    void CalculateResult(Number right_operand);
    void DoChangeSignInput();
    void DoShowResultInput();
    void DoMemoryClearInput();
    void DoMemoryStoreInput();
    void DoMemoryRemember();
};
