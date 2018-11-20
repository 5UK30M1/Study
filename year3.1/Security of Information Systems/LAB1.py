from tkinter import filedialog
import tkinter as tk
import locale
from tkinter import *
from pathlib import Path

class pflile:
    workfile = 0
    translated = ""
    key = -2000
    text = 0
    #alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ1234567890,.;!?"
    #alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890,.;!?"
    alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
    alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    def __init__(self):
        self.text = Text(root)
        scroll = Scrollbar(root, command=self.text.yview)
        self.text.configure(yscrollcommand=scroll.set)

    def about(self):
        w = Tk()
        L = Label(w, text="About tk\n\n Version 0.01\nCopyright Novak M.S. TR-61\nAll Rights Reserved")
        L.pack()

    def newf(self):
        self.text.pack()
        if(self.workfile == 0):
            self.savefas()

    def openf(self):
        root.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                   filetypes=(("txt files", "*.txt"), ("all files", "*.*")))
        self.workfile = Path(root.filename)
        self.text.insert(END,self.workfile.read_text())
        self.origtext = self.workfile.read_text()
        self.text.pack()

    def savef(self):
        self.workfile.write_text(self.text.get("end-1c linestart", "end"))

    def savefas(self):
        root.filename = filedialog.asksaveasfilename(initialdir="/", title="Select file",
                                                     filetypes=(("txt files", "*.txt"), ("all files", "*.*")))

        workfile = Path(root.filename)
        workfile.write_text(self.text.get("end-1c linestart", "end"))

    def encrypt_EN(self):
        self.key_input()
        self.key %= len(self.alphabet_EN)
        ind = 0
        for symbol in self.origtext:
            low_sybol = False
            if(symbol.islower()):
                symbol = symbol.upper()
                low_sybol = True
            num = self.alphabet_EN.find(symbol)
            if(self.alphabet_EN.find(symbol) >= 0):
                num += self.key
                if(num >= len(self.alphabet_EN)):
                    num %= len(self.alphabet_EN)
                symbol = self.alphabet_EN[num]
            if(low_sybol):
                symbol = symbol.lower()
                low_sybol = False
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.__init__()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()


    def decrypt_EN(self):
        self.key_input()
        self.key %= len(self.alphabet_EN)
        ind = 0
        for symbol in self.origtext:
            low_sybol = False
            if(symbol.islower()):
                symbol = symbol.upper()
                low_sybol = True
            num = self.alphabet_EN.find(symbol)
            if(self.alphabet_EN.find(symbol) >= 0):
                num -= self.key
                if(num <= 0):
                    num %= len(self.alphabet_EN)
                symbol = self.alphabet_EN[num]
            if(low_sybol):
                symbol = symbol.lower()
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.__init__()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def encrypt_UA(self):
        self.key_input()
        self.key %= len(self.alphabet_UA)
        ind = 0
        for symbol in self.origtext:
            low_sybol = False
            if(symbol.islower()):
                symbol = symbol.upper()
                low_sybol = True
            num = self.alphabet_UA.find(symbol)
            if(self.alphabet_UA.find(symbol) >= 0):
                num += self.key
                if(num >= len(self.alphabet_UA)):
                    num %= len(self.alphabet_UA)
                symbol = self.alphabet_UA[num]
            if(low_sybol):
                symbol = symbol.lower()
                low_sybol = False
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.__init__()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def decrypt_UA(self):
        self.key_input()
        self.key %= len(self.alphabet_UA)
        ind = 0
        for symbol in self.origtext:
            low_sybol = False
            if(symbol.islower()):
                symbol = symbol.upper()
                low_sybol = True
            num = self.alphabet_UA.find(symbol)
            if(self.alphabet_UA.find(symbol) >= 0):
                num -= self.key
                if(num <= 0):
                    num %= len(self.alphabet_UA)
                symbol = self.alphabet_UA[num]
            if(low_sybol):
                symbol = symbol.lower()
                low_sybol = False
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.__init__()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def closef(self):
        self.text.destroy()
        self.workfile = 0
        self.translated = ""
        self.key = 1
        self.text = 0
        self.alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
        self.alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        self.__init__()

    def key_input(self):
        #self.key = input()
        print(0)

    def key_input1(self):
       #print("startkey {}" , self.key)
       w = Tk()
       L = Label(w, justify = LEFT, text="Enter key")
       text = Text(w, height = 1, width = 5)
       scroll = Scrollbar(w, command=text.yview)
       text.configure(yscrollcommand=scroll.set)
       self.key = self.text.get("end-1c linestart", "end")
       Button(w, text = "Input", command = w.quit)
       L.pack()
       print("startkey {}", self.key)


def printl(lang_en):
    L = Label(root, justify = LEFT, text=lang_en)
    L.pack()

def File():
    filemenu = Menu(menubar, tearoff=0)
    filemenu.add_command(label="New", command=obj.newf)
    filemenu.add_command(label="Open", command=obj.openf)
    filemenu.add_command(label="Save", command=obj.savef)
    filemenu.add_command(label="Save as...", command=obj.savefas)
    filemenu.add_command(label="Close", command=obj.closef)
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=root.quit)
    menubar.add_cascade(label="File", menu=filemenu)

def EditEN():
    editmenu = Menu(menubar, tearoff=0)
    editmenu.add_command(label="Encrypt_ENG", command=obj.encrypt_EN)
    editmenu.add_command(label="Decrypt_ENG", command=obj.decrypt_EN)
    editmenu.add_command(label="Encrypt_UKR", command=obj.encrypt_UA)
    editmenu.add_command(label="Decrypt_UKR", command=obj.decrypt_UA)
    #editmenu.add_separator(  )
    #editmenu.add_checkbutton(label="Українська",  onvalue=0, offvalue=1, var = lang_en)
    #editmenu.add_checkbutton(label="English",  onvalue=True, offvalue=0, var = lang_en)
    menubar.add_cascade(label="Edit", menu=editmenu)

def EditUA():
    editmenu = Menu(menubar, tearoff=0)
    editmenu.add_command(label="Encryptu", command=obj.encrypt_UA)
    editmenu.add_command(label="Decryptu", command=obj.decrypt_UA)
    editmenu.add_separator()
    editmenu.add_checkbutton(label="Українська", onvalue=0, offvalue=1, var=lang_en)
    editmenu.add_checkbutton(label="English", onvalue=True, offvalue=0, var=lang_en)
    menubar.add_cascade(label="Edit", menu=editmenu)

def Help():
    helpmenu = Menu(menubar, tearoff=0)
    helpmenu.add_command(label="About...", command=obj.about)
    menubar.add_cascade(label="Help", menu=helpmenu)

###################             MAIN            ######################################

root = Tk()
obj = pflile()
lang_en = tk.BooleanVar()
lang_en.set(True)
menubar = Menu(root)
File()
EditEN()
Help()

root.config(menu=menubar)
root.mainloop()

