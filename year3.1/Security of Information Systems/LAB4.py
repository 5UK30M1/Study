from tkinter import filedialog
import tkinter as tk
import time
import random
import re
from tkinter import *
from pathlib import Path
from enum import Enum
import Pmw


def find_list(s, l):
    tmp = []
    for ind1 in range(0, len(s)):
        for ind2 in range(0, len(s[ind1])):
            if s[ind1][ind2] == l:
                tmp.append('{}/{} '.format(ind1, ind2))
    return tmp


alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lang_en = True


class EntryFormatting:
        def __init__(self, master):
            frame = Frame(master)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            self._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='Phone Number:\n(nnn)-nnn-nnn',
                format=self.fmtPhone, enter=self.activate)
            self._crdprt = self.createField(frame, width=11, row=1, col=2,
                label='SSN#:', format=self.fmtSSN,
                enter=self.activate)
            frame.pack(side=TOP, padx=15, pady=15)

        def createField(self, master, label='', text='', width=1,
            format=None, enter=None, row=0, col=0):
            Label(master, text=label).grid(row=row, column=col-1,
                 padx=15, sticky=W)
            id = Entry(master, text=text, width=width, takefocus=1)
            id.bind('<KeyRelease>', format)
            id.bind('<Return>', enter)
            id.grid(row=row, column=col, pady=10, sticky=W)
            return id

        def activate(self, event):
            print ('<Return>: value is', event.widget.get())

        def fmtSSN(self, event):
            current = event.widget.get()
            if len(current) in [3, 6]:
                current = '%s-' % current
            event.widget.delete(0, END)
            event.widget.insert(0, current)
            root = Tk()

class pflile:
    workfile = 0
    translated = ""
    origtext = ""
    key = ''
    text = 0
    A = 0
    B = 0
    C = 0
    var = BooleanVar
    String = ""
    input_type = 0
    alphabet = ""

    def __init__(self):
        self.var = BooleanVar()
        self.var.set(True)
        self.text = Text(root)
        self.text.pack()
        scroll = Scrollbar(root, command=self.text.yview)
        self.text.configure(yscrollcommand=scroll.set)
        if(self.var.get() == True):
            self.alphabet = alphabet_EN
        else:
            self.alphabet = alphabet_UA

    def reinit(self):
        self.text = Text(root)
        self.text.pack()
        scroll = Scrollbar(root, command=self.text.yview)
        self.text.configure(yscrollcommand=scroll.set)
        if(self.var.get() == True):
            self.alphabet = alphabet_EN
        else:
            self.alphabet = alphabet_UA

    def about(self):
        w = Tk()
        w.title('About')
        L = Label(w, text="About tk\n\n Version 0.01\nCopyright Novak M.S. TR-61\nAll Rights Reserved")
        L.pack()

    def newf(self):
        self.text.pack()
        if(self.workfile == 0):
            self.savefas()

    def closef(self):
        self.text.destroy()
        self.workfile = 0
        self.translated = ""
        self.key = ''
        self.text = 0
        self.reinit()

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

    def valueChanged(self):
        #print('Current value = %s' % ['Off', 'On'][self.var.get()])
        print('1')
        if(self.var.get() == True):
            self.alphabet = alphabet_EN
        else:
            self.alphabet = alphabet_UA

    def key_input(self):
        root.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                   filetypes=(("txt files", "*.txt"), ("all files", "*.*")))
        self.workfile = Path(root.filename)
        self.key = self.workfile.read_text()
        self.key = self.key.split('\n')
        print(self.key)
        print(len(self.key))

    def encrypt(self):
        for ind in range(0, len(self.origtext) - 1):
            temp = find_list(self.key, self.origtext[ind])
            print(temp)
            if (len(temp) > 0):
                symbol = temp[random.randint(0, (len(temp) - 1))]
            else:
                symbol = '{' + self.origtext[ind] + '} '
            print(symbol)
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.reinit()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def decrypt(self):
        temp = self.origtext.split()
        print(temp)
        for obj in temp:
            print(obj)
            if obj.find('{') != -1:
                symbol = obj[1]
            else:
                digits = re.findall(r'\d+', obj)
                symbol = self.key[int(digits[0])][int(digits[1])]
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.reinit()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def gk(self):
        print(self.key)

def printl(lang_en):
    L = Label(root, justify = LEFT, text=lang_en)
    L.pack()

def printt(lang):
    print(lang)

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
    editmenu.crypt = Menu(editmenu, tearoff=0)
    editmenu.crypt.add_command(label="Encrypt", command=obj.encrypt)
    editmenu.crypt.add_command(label="Decrypt", command=obj.decrypt)
    editmenu.add_cascade(label="Crypt", menu=editmenu.crypt)

    editmenu.language = Menu(editmenu, tearoff=0)
    editmenu.language.add_checkbutton\
        (label="Українська",  onvalue=False, offvalue=True, variable = obj.var, command = obj.valueChanged)
    editmenu.language.add_checkbutton\
        (label="English",  onvalue=True, offvalue=False, variable = obj.var, command = obj.valueChanged)
    editmenu.add_cascade(label="Language", menu=editmenu.language)

    editmenu.add_command(label="Input key", command=obj.key_input)
    menubar.add_cascade(label="Edit", menu=editmenu)

def Help():
    helpmenu = Menu(menubar, tearoff=0)
    helpmenu.add_command(label="About...", command=obj.about)
    menubar.add_cascade(label="Help", menu=helpmenu)

###################             MAIN            ######################################

root = Tk()
root.title('Cryptography')
obj = pflile()
#print(type)
menubar = Menu(root)
File()
EditEN()
Help()

root.config(menu=menubar)
root.mainloop()
