# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'untitledBMkWGH.ui'
##
## Created by: Qt User Interface Compiler version 6.0.3
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *
import sys


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(800, 480)
        MainWindow.setMaximumSize(QSize(800, 480))
        MainWindow.setAutoFillBackground(False)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(0, -10, 800, 480))
        self.label.setMaximumSize(QSize(800, 480))
        self.label.setLayoutDirection(Qt.LeftToRight)
        self.label.setAutoFillBackground(True)
        self.label.setFrameShape(QFrame.NoFrame)
        self.label.setPixmap(QPixmap(u":/background/D:/Project/Missile vehicle/bm-21-grad-rocket-launching-vehicle-1.snapshot.10/Untitled-1.png"))
        self.label.setAlignment(Qt.AlignBottom|Qt.AlignHCenter)
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(-20, -130, 100, 50))
        self.label_2.setMaximumSize(QSize(100, 50))
        self.label_2.setPixmap(QPixmap(u":/car/D:/Project/Missile vehicle/bm-21-grad-rocket-launching-vehicle-1.snapshot.10/Rendering 5 3.png"))
        self.doubleSpinBox = QDoubleSpinBox(self.centralwidget)
        self.doubleSpinBox.setObjectName(u"doubleSpinBox")
        self.doubleSpinBox.setGeometry(QRect(280, 330, 240, 30))
        self.doubleSpinBox_2 = QDoubleSpinBox(self.centralwidget)
        self.doubleSpinBox_2.setObjectName(u"doubleSpinBox_2")
        self.doubleSpinBox_2.setGeometry(QRect(10, 330, 240, 30))
        self.doubleSpinBox_2.setMaximumSize(QSize(1600000, 16777215))
        self.doubleSpinBox_3 = QDoubleSpinBox(self.centralwidget)
        self.doubleSpinBox_3.setObjectName(u"doubleSpinBox_3")
        self.doubleSpinBox_3.setGeometry(QRect(560, 330, 240, 30))
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(300, 380, 181, 41))
        self.Mode1 = QCheckBox(self.centralwidget)
        self.Mode1.setObjectName(u"Mode1")
        self.Mode1.setGeometry(QRect(590, 220, 201, 41))
        font = QFont()
        font.setFamily(u"Arial")
        font.setPointSize(16)
        font.setBold(True)
        self.Mode1.setFont(font)
        self.Mode1.setLayoutDirection(Qt.RightToLeft)
        self.Mode1.setChecked(False)
        self.Mode1.setTristate(False)
        self.checkBox = QCheckBox(self.centralwidget)
        self.checkBox.setObjectName(u"checkBox")
        self.checkBox.setGeometry(QRect(600, 200, 191, 20))
        self.checkBox.setFont(font)
        self.checkBox.setLayoutDirection(Qt.RightToLeft)
        self.checkBox_2 = QCheckBox(self.centralwidget)
        self.checkBox_2.setObjectName(u"checkBox_2")
        self.checkBox_2.setGeometry(QRect(520, 270, 271, 20))
        self.checkBox_2.setFont(font)
        self.checkBox_2.setLayoutDirection(Qt.RightToLeft)
        self.spinBox = QSpinBox(self.centralwidget)
        self.spinBox.setObjectName(u"spinBox")
        self.spinBox.setGeometry(QRect(470, 270, 50, 20))
        self.label_3 = QLabel(self.centralwidget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(40, 280, 171, 41))
        font1 = QFont()
        font1.setPointSize(18)
        font1.setBold(True)
        self.label_3.setFont(font1)
        self.label_3.setAlignment(Qt.AlignCenter)
        self.label_4 = QLabel(self.centralwidget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(320, 290, 171, 31))
        self.label_4.setFont(font1)
        self.label_5 = QLabel(self.centralwidget)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(600, 290, 181, 41))
        self.label_5.setFont(font1)
        self.label_6 = QLabel(self.centralwidget)
        self.label_6.setObjectName(u"label_6")
        self.label_6.setGeometry(QRect(30, 0, 161, 191))
        self.label_6.setPixmap(QPixmap(u":/LOGO/280px-\u0634\u0639\u0627\u0631_\u0627\u0644\u0645\u0639\u0647\u062f_\u0627\u0644\u0641\u0646\u064a_\u0644\u0644\u0642\u0648\u0627\u062a_\u0627\u0644\u0645\u0633\u0644\u062d\u0629_(\u0645\u0635\u0631).png"))
        self.pushButton_2 = QPushButton(self.centralwidget)
        self.pushButton_2.setObjectName(u"pushButton_2")
        self.pushButton_2.setGeometry(QRect(630, 390, 121, 31))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 800, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

    
        
            
            
    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.label.setText("")
        self.label_2.setText("")
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"\u0627\u0637\u0644\u0627\u0642 ", None))
        self.Mode1.setText(QCoreApplication.translate("MainWindow", u"\u0627\u0637\u0644\u0627\u0642 \u0643\u0644 \u0635\u0627\u0631\u0648\u062e \u0645\u0646\u0641\u0631\u062f ", None))
        self.checkBox.setText(QCoreApplication.translate("MainWindow", u"\u0627\u0637\u0644\u0627\u0642 \u062c\u0645\u064a\u0639 \u0627\u0644\u0635\u0648\u0627\u0631\u064a\u062e ", None))
        self.checkBox_2.setText(QCoreApplication.translate("MainWindow", u"\u0627\u0637\u0644\u0627\u0642 \u0643\u0644 \u0635\u0627\u0631\u0648\u062e \u0628\u0639\u062f \u0645\u062f\u0647 \u0632\u0645\u0646\u064a\u0647 ", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"x coordinates", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"y coordinates", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"z coordinates", None))
        self.label_6.setText("")
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"\u0627\u0644\u0627\u0636\u0627\u0621\u0629", None))
    # retranslateUi

class MainWindow(QMainWindow):

    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        
   
  
        
if __name__ == '__main__':

    app = QApplication(sys.argv) 
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())