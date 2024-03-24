#ifndef QLOG_UI_MAINWINDOW_H
#define QLOG_UI_MAINWINDOW_H

#include <QMainWindow>
#include "ui/StatisticsWidget.h"
#include "ui/SwitchButton.h"
#include "core/NetworkNotification.h"
#include "core/AlertEvaluator.h"
#include "ui/AlertWidget.h"
#include "core/PropConditions.h"
#include "core/MembershipQE.h"
#include "core/ClubLog.h"

namespace Ui {
class MainWindow;
}

class QLabel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent* event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void settingsChanged();
    void alertRulesChanged();
    void themeChanged(int);
    void altBackslash(bool active);
    void manualMode(bool);
    void layoutChanged();

public slots:
    void rigErrorHandler(const QString &error, const QString &errorDetail);
    void rotErrorHandler(const QString &error, const QString &errorDetail);
    void cwKeyerErrorHandler(const QString &error, const QString &errorDetail);
    void stationProfileChanged();

private slots:
    void rigConnect();
    void rotConnect();
    void cwKeyerConnect();
    void cwKeyerConnectProfile(QString);
    void cwKeyerDisconnectProfile(QString);
    void showSettings();
    void showStatistics();
    void importLog();
    void exportLog();
    void showLotw();
    void showeQSL();
    void showClublog();
    void showHRDLog();
    void showQRZ();
    void showAwards();
    void showAbout();
    void showWikiHelp();
    void showMailingList();
    void showReportBug();
    void showAlerts();
    void clearAlerts();
    void conditionsUpdated();
    void QSOFilterSetting();
    void alertRuleSetting();
    void darkModeToggle(int);
    void processSpotAlert(SpotAlert alert);
    void clearAlertEvent();
    void beepSettingAlerts();
    void shortcutALTBackslash();
    void setManualContact(bool);
    void showEditLayout();
    void setLayoutGeometry();
    void saveProfileLayoutGeometry();
    void setEquipmentKeepOptions(bool);

private:
    Ui::MainWindow* ui;
    QLabel* conditionsLabel;
    QLabel* profileLabel;
    QLabel* callsignLabel;
    QLabel* locatorLabel;
    QPushButton* alertButton;
    QPushButton* alertTextButton;
    SwitchButton* darkLightModeSwith;
    QLabel* darkIconLabel;
    StatisticsWidget* stats;
    AlertWidget* alertWidget;
    NetworkNotification networknotification;
    AlertEvaluator alertEvaluator;
    PropConditions *conditions;
    QSettings settings;
    bool isFusionStyle;
    ClubLog* clublogRT;

    void setDarkMode();
    void setLightMode();

    void setupLayoutMenu();
    void saveEquipmentConnOptions();
    void restoreConnectionStates();
    void restoreEquipmentConnOptions();
};

#endif // QLOG_UI_MAINWINDOW_H
