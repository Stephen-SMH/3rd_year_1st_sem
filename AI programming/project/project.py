import psutil

import sys

from PySide6.QtWidgets import *
from PySide6.QtCore import *
from sysUI_ui import Ui_MainWindow

class TestUI(QMainWindow):

      def __init__(self):
            super().__init__()
            self.ui = Ui_MainWindow()
            self.ui.setupUi(self)
      
            self.timer = QTimer()
            self.timer.timeout.connect(self.update_ui)
            self.timer.start(1000)
      
      def update_ui(self):
            cpu_usage = psutil.cpu_percent()
            mem_usage = psutil.virtual_memory().percent
            disk_usage = psutil.disk_usage('/').percent
            network_usage = psutil.net_io_counters().bytes_sent + psutil.net_io_counters().bytes_recv
            battery_usage = psutil.sensors_battery().percent

            power_plugged = psutil.sensors_battery().power_plugged
            if power_plugged:
                  self.ui.Battery_Label.setText("Charging")
            else:
                  self.ui.Battery_Label.setText("Battery")

            process = psutil.process_iter()

            processes = []
            for p in process:
                  processes.append(p.name())

            
            threads = psutil.cpu_count()

      
            self.ui.cpu_LineEdit.setText(f"{cpu_usage}%")
            self.ui.mem_LineEdit.setText(f"{mem_usage}%")
            self.ui.disk_LineEdit.setText(f"{disk_usage}%")
            self.ui.network_LineEdit.setText(f"{network_usage} Bytes")
            self.ui.battery_LineEdit.setText(f"{battery_usage}%")
            self.ui.power_LineEdit.setText(f"{power_plugged}")
            self.ui.process_LineEdit.setText(f"{processes}")  
            self.ui.threads_LineEdit.setText(f"{threads}")
            

if __name__ == "__main__":
      app = QApplication(sys.argv)
      window = TestUI()
      window.show()
      sys.exit(app.exec_())