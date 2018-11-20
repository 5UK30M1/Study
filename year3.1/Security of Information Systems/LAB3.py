from tkinter import filedialog
import random
from tkinter import *
from pathlib import Path
import Pmw

lang_en = True
alphabet_UA = \
    "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯабвгґдеєжзиіїйклмнопрстуфхцчшщьюя 1234567890,;:\|!?"
alphabet_EN = \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .1234567890,;:\|!?"

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
    seed = 15
    text = 0
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
        self.seed = 1
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

    def crypting(self):
        s_ind = -1
        print(self.origtext)
        for ind in range(0, len(self.origtext)):
            s_ind += 1
            if (s_ind >= len(self.String)):
                s_ind %= len(self.String)
            if(self.alphabet.find(self.origtext[ind]) == -1 or
                    self.alphabet.find(self.String[s_ind]) == -1):
                continue
            symbol = self.alphabet[
                abs(self.alphabet.find(self.origtext[ind]) ^
                self.alphabet.find(self.String[s_ind])) %
                abs(len(self.alphabet))]
            self.translated += symbol
        print(self.translated)
        self.text.destroy()
        self.reinit()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def seed_input(self):
        self.input_type = 0
        choice = None
        dialog = Pmw.CounterDialog(root,
            label_text='Enter the seed\n',
            counter_labelpos=N, entryfield_value=self.seed,
            counter_datatype='integer',
            entryfield_validate={'validator': 'integer'},
            buttons=('OK', 'Cancel'), defaultbutton='OK',
            title='seed')
        dialog.tkraise()
        result = dialog.activate()
        print ('You clicked on', result, dialog.get())
        self.seed = dialog.get()

    def gamma_input(self):
            T = Tk()
            T.title("Input (String)")
            frame = Frame(T)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            T._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='String',
                format='string', enter=self.set_String)
            frame.pack(side=TOP, padx=15, pady=15)
            self.activate()
            Button(T, text = "OK", command = T.destroy).pack()

    def gen_gamma(self):
        random.seed(self.seed)
        self.String = ""
        for ind in range(0, len(self.origtext)):
            self.String += self.alphabet[random.randint(0,len(self.alphabet) - 50)]
        print(self.String)

    def get_gamma(self):
        T = Tk()
        e = self.String
        Label(T, text="Gamma:").pack(side=LEFT, padx=5, pady=10)
        Label(T, text = e).pack(side=RIGHT, padx=5, pady=10)


    def set_String(self,event):
        self.String = str(event.widget.get())

    def createField(self, master, label='', text='', width=1,
            format=None, enter=None, row=0, col=0):
            Label(master, text=label).grid(row=row, column=col-1,
                 padx=15, sticky=W)
            id = Entry(master, text=text, width=width, takefocus=1)
            id.bind('<KeyRelease>', format)
            id.bind('<Return>', enter)
            id.grid(row=row, column=col, pady=10, sticky=W)
            return id

    def activate(self):
        #print ('<Return>: value is', event.widget.get())
        print ('A: value is', self.A)
        print ('B: value is', self.B)
        print ('C value is', self.C)
        print ('String: value is', self.String)
        #return event.widget.get()

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
    editmenu.add_command(label="Encrypt", command=obj.crypting)

    editmenu.add_checkbutton\
        (label="Українська",  onvalue=False, offvalue=True, variable = obj.var, command = obj.valueChanged)
    editmenu.add_checkbutton\
        (label="English",  onvalue=True, offvalue=False, variable = obj.var, command = obj.valueChanged)

    #editmenu.add_command(label="Input Gamma", command=obj.gamma_input)
    editmenu.add_command(label="Input generation seed", command=obj.seed_input)
    editmenu.add_command(label="Generate Gamma", command=obj.gen_gamma)
    editmenu.add_command(label="Get Gamma", command=obj.get_gamma)
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
