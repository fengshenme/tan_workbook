import tkinter as tk
import tkinter.ttk as ttk
from tkinter import messagebox as mb

import threading
import time
import serial
from serial import serialutil
from serial.tools import list_ports as ltpt
import inspect
import sys

from app.hard_tool.ser_tool import SerTool 



class TSerial():

    def __init__(self, maf):        
        self.serv = maf  
        self.picxls = []  
        self.serflag = True
        self.init_ui()

    def init_ui(self):
        self.ser = serial.Serial()
        # self.buback.pack_forget()
        self.group = tk.LabelFrame(self.serv, text="主显示区")
        self.group.pack()

        self.paren = tk.LabelFrame(self.group, text="配置选项")
        self.paren.pack(side=tk.LEFT,  fill=tk.Y)

        lf2 = tk.LabelFrame(self.group, text="输出显示", height=50)
        lf2.pack(side=tk.TOP, fill=tk.X)
        self.lf3 = tk.LabelFrame(self.group, text="输入框", height=50)
        self.lf3.pack(side=tk.TOP, fill=tk.BOTH,expand=True)

        f1 =tk.Frame(self.paren)    
        f1.pack(padx=5, pady=5)

        baudrates = [str(baud) for baud in self.ser.BAUDRATES ]

        lt1 = ["python",'java', 'c++']
        sl_titles = ['端  口', '波特率', '数据位', '停止位', '奇偶校验',  '流控']
        
        
        for i,v in enumerate(sl_titles) :
            tk.Label(f1, text=v,  width= 8).grid(row=i, column=0, ipadx=1, pady=2)
    
        ports = [portname for (portname, desc, hwid) in sorted(ltpt.comports())]
        parity_names = [serialutil.PARITY_NAMES[p] for p in self.ser.PARITIES]
        lkls = ['无', 'XON/XOFF', 'RTS/CTS'] 
        if not len(ports) :
            ports.append('没有串口')
        self.sel_conf = [ports, self.ser.BAUDRATES, self.ser.BYTESIZES, self.ser.STOPBITS, parity_names, lkls]

        self.ser_conf = [tk.StringVar() for x in range(0, 6, 1)]
        for i in range(6) :
            cbb = ttk.Combobox(f1, textvariable=self.ser_conf[i], value=self.sel_conf[i])
            cbb.current(0) # 设置默认选项 
            cbb.grid(row=i, column=1, pady=5)   
        
        # 文字显示区
        text_width , text_height = 80, 22
        self.texts = tk.Text(lf2)
        ysc = tk.Scrollbar(lf2)
        ysc.pack(side=tk.RIGHT, fill=tk.Y)
        self.texts.pack(fill=tk.X)
        ysc.config(command=self.texts.yview)
        self.texts.config(yscrollcommand=ysc.set)

        txtcmd = tk.Text(self.lf3)
        txtcmd.pack(fill=tk.BOTH,expand=True)

        self.seropen = tk.Button(f1, text='打开串口', command=lambda : self.open_ser(),  width=10)
        self.seropen.grid(row=6, column=0, ipadx=1, pady=2 )
        self.ser_close = tk.Button(f1, text='关闭串口', command=lambda : self.close_ser(), width=10)
        self.ser_close.config(state=tk.DISABLED)
        self.ser_close.grid(row=6, column=1, ipadx=1, pady=2)
        tk.Button(f1, text='清除输出', command=lambda : self.texts.delete(1.0, tk.END), width=10).grid(row=7, column=0, ipadx=1, pady=2 )
        tk.Button(f1, text='发送', command=lambda : self.send_cmd(txtcmd.get(1.0 , tk.END)), width=10).grid(row=7, column=1, ipadx=1, pady=2)

        tk.Label(f1, textvariable=self.ser_conf[1],  width= 8).grid(row=8, column=0, columnspan=3, ipadx=1, pady=2)
        # 滚动条显示
    def send_cmd(self, msg):
        if msg != None:
            msg = f'{msg}\r\n'
            self.ser.write(msg.encode('utf-8'))
            
        SerTool().logshow(sys._getframe(), f'{msg}')

    def open_ser(self):
        self.ser_close.config(state=tk.NORMAL)
        self.seropen.config(state=tk.DISABLED)
        self.ser.timeout = 0.5
        try:
            self.ser.port = self.ser_conf[0].get()
            self.ser.baudrate = self.ser_conf[1].get()
            self.ser.bytesize = int(self.ser_conf[2].get())
            self.ser.stopbits = int(self.ser_conf[3].get())
            self.ser.parity = [p for p in self.ser.PARITIES if serialutil.PARITY_NAMES[p] == self.ser_conf[4].get()][0]
            l_co = self.ser_conf[5].get()
            self.ser.xonxoff = 1 if l_co == 'XON/XOFF'   else 0
            self.ser.rtscts = 1 if l_co == 'RTS/CTS' else 0
            self.ser.open()
       
            if self.ser.isOpen(): 
                self.serflag = True
                self.tsr = threading.Thread(target=self.read_ser)
                self.tsr.start()
        except ValueError as e:
            self.ser_close.config(state=tk.DISABLED )
            self.seropen.config(state=tk.NORMAL)
            SerTool().logshow(sys._getframe(), f'{e}') 

        if not self.ser.isOpen():
            mb.showinfo(title='提示信息', message='串口打开失败, 请配置串口连接数据')      

    def read_ser(self):
        while self.serflag:
            rstr = self.ser.read_all().decode('utf-8','ignore')
            if rstr.strip() != '' :
            
                fenjiex = '------------->\n'
                self.texts.insert(tk.END, fenjiex)
                self.texts.insert(tk.END, rstr)
            time.sleep(0.5)

    def close_ser(self):
        self.ser_close.config(state=tk.DISABLED )
        self.seropen.config(state=tk.NORMAL)
        self.serflag = False
        self.ser.close()
        