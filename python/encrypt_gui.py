from tkinter import *
from tkinter.ttk import *
from encrypt02 import Encrypt
import os

#Encrypt的GUI類別
class EncryptGUI(Frame):
    #設定初值
    def __init__(self,master=None):
        Frame.__init__(self,master)
        self.grid()
        self.creatWidgets()
        self.e = None
        self.userinput = ""
        self.result = ""

    #建立所有視窗元件
    def creatWidgets(self):
        self.it = Label(self)
        self.it["text"] = "Input:"
        self.it.grid(row = 0,column = 0)
        
        self.ifd = Entry(self)
        self.ifd["width"] = 60
        self.ifd.grid(row = 0,column = 1,columnspan = 6)
        
        self.ot = Label(self)
        self.ot["text"] = "Output:"
        self.ot.grid(row = 1,column = 0)
        
        self.ofd = Entry(self)
        self.ofd["width"] = 60
        self.ofd.grid(row = 1,column = 1,columnspan = 6)



        self.nb = Button(self)
        self.nb["text"] = "New"
        self.nb.grid(row = 2,column = 0)
        self.nb["command"] = self.nm

        self.lb = Button(self)
        self.lb["text"] = "Load"
        self.lb.grid(row = 2,column = 1)
        self.lb["command"] = self.lm
        
        self.sb = Button(self)
        self.sb["text"] = "Save"
        self.sb.grid(row = 2,column = 2)
        self.sb["command"] = self.sm
        
        self.eb = Button(self)
        self.eb["text"] = "Encode"
        self.eb.grid(row = 2,column = 3)
        self.eb["command"] = self.em
        
        self.db = Button(self)
        self.db["text"] = "Decode"
        self.db.grid(row = 2,column = 4)
        self.db["command"] = self.dm
        
        self.cb = Button(self)
        self.cb["text"] = "Clear"
        self.cb.grid(row = 2,column = 5)
        self.cb["command"] = self.cm
        
        self.cb2 = Button(self)
        self.cb2["text"] = "Copy"
        self.cb2.grid(row = 2,column = 6)
        self.cb2["command"] = self.cm2

        

        self.dt = Label(self)
        m = "something happened"
        self.dt["text"] = m
        self.dt.grid(row = 3 ,column = 0 ,columnspan = 7)

    #按下New按鈕的事件
    def nm(self):
        self.e = Encrypt()
        self.dt["text"] = self.e
    #按下Load按鈕的事件
    def lm(self):
        #檢查檔案是否存在
        if os.path.exists("./code.txt"):
            #進行載入工作
            f = open('./code.txt','r')
            code = f.readline()
            self.e = Encrypt(code)
            s = str("".join(self.e.code))
            m = "code:" + s
            self.dt["text"] = m
        else:
            m = "Load denied!"
            self.dt["text"] = m
    #按下Save按鈕的事件
    def sm(self):
        #檢查是否有按過New按鈕
        if self.e == None:
            m = "it can't save!"
            self.dt["text"] = m
        else:
            #進行存檔工作
            f = open('./code.txt','w')
            f.write("".join(self.e.code))
            f.closed
            self.dt["text"] = "It's Done!"
    #按下Encode按鈕的事件
    def em(self):
        #取得使用者輸入
        self.userinput = self.ifd.get()

        #測試使用者是否有輸入
        if self.userinput == "":
            m = "No input string!"
            self.dt["text"] = m
        else:
            #測試是否有按過New
            if self.e == None:
                m = "No encrypt object"
                self.dt["text"] = m
            else:
                #使用只有輸入並且有按過New按鈕
                s = self.userinput
                r = self.e.toEncode(s)
                self.result = r
                self.ofd.delete(0,200)
                self.ofd.insert(0,r)
                m = "Encoding success!"
                self.dt["text"] = m
    #按下Decode按鈕的事件
    def dm(self):
        #取得使用者輸入
        self.userinput = self.ifd.get()

        #測試使用者是否有輸入
        if self.userinput == "":
            m = "No input string!"
            self.dt["text"] = m
        else:
            #測試是否有按過New
            if self.e == None:
                m = "No encrypt object"
                self.dt["text"] = m
            else:
                #使用只有輸入並且有按過New按鈕
                s = self.userinput
                r = self.e.toDecode(s)
                self.result = r
                self.ofd.delete(0,200)
                self.ofd.insert(0,r)
                m = "Decoding success!"
                self.dt["text"] = m
    #按下Clear按鈕的事件
    def cm(self):
        self.e = None
        self.userinput = ""
        self.Output = ""
        self.ifd.delete(0,200)
        self.ofd.delete(0,200)
        self.dt["text"] = "Clear all~"
    #按下Copy按鈕的事件
    def cm2(self):
        if self.result == "":
            m = "copy denied!"
            self.dt["text"] = m
        else:
            self.clipboard_clear()
            r = self.result
            self.clipboard_append(r)
            m = "It's copied."
            self.dt["text"] = m

#GUI執行部分
if __name__ == "__main__":
    root = Tk()
    root.title("HEllo~")
    # root.iconbitmap('1.jpg')
    root.resizable(False,True)
    app = EncryptGUI(master = root)
    app.mainloop()
