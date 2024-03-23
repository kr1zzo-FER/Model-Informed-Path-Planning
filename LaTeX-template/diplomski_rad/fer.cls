% Predložak za završne i diplomske radove na
% Sveučilištu u Zagrebu Fakultetu elektrotehnike i računarstva
% 
% Kratki pregled opcija:
% diplomskirad - pisanje diplomskog rada na hrvatskom jeziku (odabrano ako nema zadanih opcija)
% zavrsnirad - pisanje završnog rada na hrvatskom jeziku
% seminarskirad - pisanje seminara na hrvatskom jeziku
% masterthesis - pisanje diplomskog rada na engleskom jeziku
% bachelorthesis - pisanje završnog rada na engleskom jeziku
% authoryear - stil citiranja autor-godina (kojeg treba zabraniti)
% upload - za izbacivanje naslovnice i teksta zadatka iz generiranog dokumenta
%
% Materijali korišteni za pripremu su razni predlošci za ispite i nastavne materijale
% te predložak za diplomske i završne radove kojeg su pripremili studenti na početku
% FER2 programa.
%
% 2020-06-10 Tomislav Petković (tomislav.petkovic.jr@fer.hr)

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{fer}[2021/06/10 FER3]

% Za definiranje što se događa pri pojedinoj opciji koristimo zastavice.
% Standardni predložak je za diplomski rad na hrvatskom jeziku pa nam za
% taj slučaj ne treba posebna zastavica te zato definiramo zastavice samo
% za završni rad i za seminar.
\newif\if@hrvatski\global\@hrvatskitrue
\newif\if@zavrsni\global\@zavrsnifalse
\newif\if@seminar\global\@seminarfalse

% Na FERWeb se učitava PDF bez naslovnice i teksta zadatka;
% zastavicu koristimo kako bi isključili \maketitle i \zadatak.
\newif\if@upload\global\@uploadfalse

% Standardni način citiranja jest brojčano citiranje pa nam samo treba
% zastavica za slučaj citiranja autor-godina koji je problematičan
% i kojeg je najbolje izbjegavati (jer: kako se citiraju upute za korištenje
% sofvera neke kompanije te kako se citira Internetska stranica za koje
% uobičajeno nema autora, zatim kako se rješava kolizija kada postoji
% više radova istog autora unutar iste godine, itd.).
\newif\if@citeauthoryear\global\@citeauthoryearfalse

% Deklariraj zastavicu za verziju dokumenta za učitavanje na FERWeb.
\DeclareOption{upload}{\@uploadtrue}

% Deklariraj zastavicu za citiranje autor-godina
\DeclareOption{authoryear}{\@citeauthoryeartrue}

% Deklarariraj zastavice za dozvoljene vrste radova
\DeclareOption{diplomski}{\@hrvatskitrue\@zavrsnifalse\@seminarfalse}
\DeclareOption{diplomskirad}{\@hrvatskitrue\@zavrsnifalse\@seminarfalse}
\DeclareOption{zavrsni}{\@hrvatskitrue\@zavrsnitrue\@seminarfalse}
\DeclareOption{zavrsnirad}{\@hrvatskitrue\@zavrsnitrue\@seminarfalse}
\DeclareOption{seminar}{\@hrvatskitrue\@zavrsnifalse\@seminartrue\@uploadfalse}
\DeclareOption{seminarskirad}{\@hrvatskitrue\@zavrsnifalse\@seminartrue\@uploadfalse}
\DeclareOption{masterthesis}{\@hrvatskifalse\@zavrsnifalse\@seminarfalse}
\DeclareOption{bachelorthesis}{\@hrvatskifalse\@zavrsnitrue\@seminarfalse}
\DeclareOption{essay}{\@hrvatskifalse\@zavrsnifalse\@seminartrue\@uploadfalse}

% Proslijedi opcije polaznoj klasi
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{report}}

% Procesiraj opcije
\ProcessOptions\relax

% Započinjemo od klase report u jednostupčanoj verziji s veličinom fonta 12pt
\LoadClass[12pt, onecolumn]{report}

% Pomoćni paketi potrebni za definiranje klase
\RequirePackage{ltxcmds}
\RequirePackage{letltxmacro}
\RequirePackage{etoolbox}

% Koristimo UTF-8 (koji je danas podržan na svim operativnim sustavima)
% Font Open Sans ćemo koristiti za naslove i naslovnicu, a Stix 2 će
% biti standardni font cijelog dokumenta.
\RequirePackage[T1]{fontenc}
\RequirePackage[utf8]{inputenc}
\RequirePackage{opensans}
%\RequirePackage{stix2}
% Potrebno za ispravno kopiranje teksta (dijakritičkih znakova) iz PDF-a
%\input{glyphtounicode}
\pdfgentounicode=1

% Jezik rada može biti ili hrvatski ili engleski što definira zastavica @hrvatski.
% Bilješka: u slučaju dodavanja ostalih stranih jezika, npr. njemačkog, potrebno
% je definirati posebne zastavice za svaki od dodatnih podržanih stranih jezika.
\if@hrvatski
\RequirePackage[main=croatian,english]{babel}
\else
\RequirePackage[main=english,croatian]{babel}
\fi
\addto\captionscroatian{\def\bibname{Literatura}\def\appendixname{Privitak}}
\addto\captionsenglish{\def\bibname{References}}

% Papir je A4, margine su 2.5cm osim unutrašnje koja je 3cm.
% Prema uputama naslovnica ima gornju i donju marginu 3cm što ćemo ispraviti
% dodavanje 0.5cm prilikom generiranja naslovnice.
\RequirePackage[a4paper, inner=3cm, outer=2.5cm, bottom=2.5cm, top=2.5cm]{geometry}

% Prored teksta je 1.5 u tijelu dokumenta.
% Opisi slika i bilješke su u normalnom proredu.
\RequirePackage{setspace}
\setstretch{1.5}

% Nakon svakog odlomka slijedi dodatni razmak od pola visine reda.
\RequirePackage[indent]{parskip}

% Potrebno za uključivanje PDF-ova zadatka diplomskog ili završnog rada.
\RequirePackage{pdfpages}

% Ako je citiranje autor-godina onda učitaj natbib.
% Ovisno o tipu citiranja i jeziku odaberi odgovarajuću bst datoteku za bibtex.
% Za numeričko citiranje koje je odabrano modificirali smo IEEE-ovu klasu;
% a za citiranje autor-godina modificiranu plainnat klasu.
% Sve .bst klase nisu univerzalne obzirom na jezik pa zato trebamo i HR i EN varijante.
\if@citeauthoryear
\RequirePackage[authoryear, round]{natbib}
\let\old@cite\cite
\renewcommand{\cite}[1]{\citep{#1}}
\if@hrvatski
\bibliographystyle{fer_plainnat_HR}
\else
\bibliographystyle{fer_plainnat_EN}
\fi
\else
\let\old@bibliography\bibliography
\def\bibliography#1{%
  \bgroup%
  \rightskip=0pt plus 1fil\relax%
  \old@bibliography{#1}
  \egroup}%
\if@hrvatski
\bibliographystyle{fer_IEEEtran_HR}
\else
\bibliographystyle{fer_IEEEtran_EN}
\fi
\fi

% Potrebno za redefiniranje oznaka slika i tablica
\RequirePackage{caption}

% Ostali standardni paketi od interesa
\RequirePackage{amssymb}
\RequirePackage{amsmath}
\RequirePackage{graphicx}

% Popis referenci (literatura) se nalazi u sadržaju
\RequirePackage[nottoc]{tocbibind}

% Za automatsko povezivanje referenci, slika i tablica koristimo hyperref
\PassOptionsToPackage{hyphens}{url}
\RequirePackage[pdfpagelabels,unicode=true,pdfa,pdfstartview=]{hyperref}

% Predefiniramo sve funkcije za tekstualne elemenate naslovnice pa zatim
% postavljamo odabrane početne vrijednosti za HR i za EN naslovnicu.
\def\unizgHR#1{\gdef\@unizgHR{#1}}
\def\ferHR#1{\gdef\@ferHR{#1}}
\def\radHR#1{\gdef\@radHR{#1}}
\def\oznakabrojaHR#1{\gdef\@oznakabrojaHR{#1}}
\def\oznakamentoraHR#1{\gdef\@oznakamentoraHR{#1}}
\def\mjestoHR#1{\gdef\@mjestoHR{#1}}

\gdef\@unizgHR{SVEU\v{C}ILI\v{S}TE U ZAGREBU}
\gdef\@ferHR{FAKULTET ELEKTROTEHNIKE I RA\v{C}UNARSTVA}
\gdef\@radHR{\if@zavrsni ZAVR\v{S}NI RAD\else\if@seminar SEMINARSKI RAD\else DIPLOMSKI RAD\fi\fi}
\gdef\@oznakabrojaHR{br.\@}
\gdef\@oznakamentoraHR{\if@seminar Voditelj:\else Mentor:\fi}
\gdef\@mjestoHR{Zagreb}

\def\unizgEN#1{\gdef\@unizgEN{#1}}
\def\ferEN#1{\gdef\@ferEN{#1}}
\def\radEN#1{\gdef\@radEN{#1}}
\def\oznakabrojaEN#1{\gdef\@oznakabrojaEN{#1}}
\def\oznakamentoraEN#1{\gdef\@oznakamentoraEN{#1}}
\def\mjestoEN#1{\gdef\@mjestoEN{#1}}

\gdef\@unizgEN{UNIVERSITY OF ZAGREB}
\gdef\@ferEN{FACULTY OF ELECTRICAL ENGINEERING AND COMPUTING}
\gdef\@radEN{\if@zavrsni BACHELOR THESIS\else\if@seminar ESSAY\else MASTER THESIS\fi\fi}
\gdef\@oznakabrojaEN{No.\@}
\gdef\@oznakamentoraEN{\if@seminar Academic Advisor:\else Mentor:\fi}
\gdef\@mjestoEN{Zagreb}

% Ovisno o vrsti rada autor mora definirati podatke koje ne možemo znati unaprijed.
% LaTeX-ova klasa report standardno definira title, author i date kojima dodajemo
% hrvatske naslov, autor i datum. Radi praktičnosti ako je jezik rada hrvatski onda
% odmah kopiramo standardne \@author, \@title i \@date u pripadne \@autor, \@naslov
% i \@datum.
\def\naslov#1{\gdef\@naslov{#1}}
\def\autor#1{\gdef\@autor{#1}}
\def\datum#1{\gdef\@datum{#1}}
\def\brojrada#1{\gdef\@brojrada{#1}}
\def\mentor#1{\gdef\@mentor{#1}}
\if@hrvatski
\gdef\@naslov{\@title}
\else
\gdef\@naslov{\@latex@warning@no@line{Naslov nije naveden. Koristi \noexpand\naslov za definiranje.}}
\fi
\gdef\@autor{\@author}
\gdef\@datum{\@date}
\gdef\@mentor{\@latex@warning@no@line{Mentor nije naveden. Koristi \noexpand\mentor za imenovanje.}}
\gdef\@brojrada{\@latex@warning@no@line{Broj rada nije naveden. Koristi \noexpand\brojrada za definiranje broja rada.}}

% Za seminar nema broja rada
\if@seminar
\brojrada{\relax}
\oznakabrojaHR{\relax}
\oznakabrojaEN{\relax}
\fi

% Naslovnica i nazivi poglavlja sukladno FER-ovom predlošku pripremljenom u Microsoftovom Wordu
% i uputama koriste Arial u zadanim veličinama. Kao zamjenski font koristimo Open Sans,
% vidi https://tug.org/FontCatalogue/opensans/, koji je standardno uključen u TeXLive i
% koji je dobra alternativa za Arial.
\def\arial#1#2{\fontfamily{\opensansfamily}\fontshape{n}\fontsize{#1}{#2}\selectfont}
\def\arialbold#1#2{\fontfamily{\opensansfamily}\fontseries{bx}\fontshape{n}\fontsize{#1}{#2}\selectfont}

% Radi lakšeg usklađivanja hrvatske i engleske naslovnice predefiniramo veličine slova.
\def\arialsveuciliste{\arial{14}{14}}
\def\arialfakultet{\arialbold{14}{14}}
\def\arialrad{\arial{14}{14}}
\def\arialnaslov{\arialbold{20}{22}}
\def\arialautor{\arial{14}{14}}
\def\arialmentor{\arial{14}{14}}
\def\arialnadnevak{\arial{14}{14}}

% Pomoćna okolina za definiranje naslovnica koja zamjenjuje standardnu titlepage.
% Potrebna je jer ako se rad piše na stranom jeziku onda moramo umetnuti dvostruku
% naslovnicu uz ispravno numeriranje stranica.
\newenvironment{naslovnica}[1]
{%
  \if@twocolumn
  \@restonecoltrue\onecolumn
  \else
  \@restonecolfalse\newpage
  \fi
  \thispagestyle{empty}%
  \setcounter{page}{#1}
}%
{\if@restonecol\twocolumn \else \newpage \fi
} 

% Definiraj hrvatsku naslovnicu.
\newcommand{\@NASLOV}{\expandafter\MakeUppercase\expandafter{\@naslov}}
\newcommand{\maketitleHR}[1]{%
  \begin{naslovnica}{#1}%
    \begin{otherlanguage}{croatian}%
      \bgroup%
      \nointerlineskip\vskip 0.5cm\null\vskip 0pt%
      \hbox to \textwidth{\hss\arialsveuciliste\@unizgHR\hss}%
      \vskip 3pt%
      \hbox to \textwidth{\hss \arialfakultet\@ferHR\hss}%
      \vskip 12pt plus 0.7fill%
      \hbox to \textwidth{\hss\arialrad \@radHR\ \@oznakabrojaHR~\@brojrada\hss}%
      \vskip 28pt%
      \bgroup\centering%
      {\arialnaslov\@NASLOV\par}%
      \vskip 22pt%
      {\arialautor%
        \begin{tabular}[t]{c}%
          \@autor%
        \end{tabular}\par}%
      \egroup
      {\if@seminar\vskip 20pt\hbox to \textwidth{\hss\arialmentor\@oznakamentoraHR\enskip\@mentor\hss}\fi}%
      \vskip 12pt plus 1fill%
      \hbox to \textwidth{\hss\arialnadnevak \@mjestoHR, \@datum\hss}%
      \vskip 0.5cm\null\vskip 0pt%
      \egroup%
    \end{otherlanguage}%
  \end{naslovnica}%
}

% Definiraj englesku naslovnicu.
\newcommand{\@TITLE}{\expandafter\MakeUppercase\expandafter{\@title}}
\newcommand{\maketitleEN}[1]{%
  \begin{naslovnica}{#1}%
    \begin{otherlanguage}{english}%
      \bgroup%
      \nointerlineskip\vskip 0.5cm\null\vskip 0pt%
      \hbox to \textwidth{\hss\arialsveuciliste\@unizgEN\hss}%
      \vskip 3pt%
      \hbox to \textwidth{\hss\arialfakultet\@ferEN\hss}%
      \vskip 12pt plus 0.7fill%
      \hbox to \textwidth{\hss\arialrad\@radEN\ \@oznakabrojaEN~\@brojrada\hss}%
      \vskip 28pt%
      \bgroup\centering%
      {\arialnaslov\@TITLE\par}%
      \vskip 22pt%
      {\arialautor%
        \begin{tabular}[t]{c}%
          \@author%
        \end{tabular}\par}%
      \egroup%
      {\if@seminar\vskip 20pt\hbox to \textwidth{\hss\arialmentor\@oznakamentoraEN\enskip\@mentor\hss}\fi}%
      \vskip 12pt plus 1fill%
      \hbox to \textwidth{\hss\arialnadnevak\@mjestoEN, \@date\hss}%
      \vskip 0.5cm\null\vskip 0pt%
      \egroup%
    \end{otherlanguage}%
  \end{naslovnica}%
}

% Definiraj naslovnicu.
\renewcommand\maketitle{%
  \if@upload\relax\else
  \setstretch{1.0}%
  \if@hrvatski\maketitleHR{1}%
  \else\maketitleEN{1}\maketitleHR{2}%
  \fi%
  \setstretch{1.5}%
  \fi%
  \global\let\maketitle\relax
  \global\let\and\relax
}

% Dodavanje teksta zadatka završnog ili diplomskog rada iz PDF-a.
% Ako je argument funkcije nepostojeća datoteka automatski se ispisuje
% tekst s uputama. U slučaju rada na stranom jeziku tekst zadatka
% zauzima dvije stranice, prva za zadatak na stranom jeziku te druga
% za zadatak na hrvatskom.
\newcommand{\zadatak}[1]{%
  \if@seminar\relax\else
  \if@upload\relax\else
  \openin15={#1}%
  \ifeof15
  \bgroup
  \centering
  \if@hrvatski
  \clearpage
  \thispagestyle{empty}%
  \vspace*{\fill}%
  Ovdje dolazi tekst zadatka \if@zavrsni zavr\v{s}nog rada\else diplomskog rada\fi\ na hrvatskom jeziku.\par%  
  \vspace*{\fill}%
  \else
  \clearpage
  \thispagestyle{empty}%
  \vspace*{\fill}%
  The \if@zavrsni bachelor\else master\fi\ thesis assignment text in English goes here.\par%
  \vspace*{\fill}%
  \newpage
  \thispagestyle{empty}%
  \vspace*{\fill}%
  Ovdje dolazi tekst zadatka \if@zavrsni zavr\v{s}nog rada\else diplomskog rada\fi\ na hrvatskom jeziku.\par%
  \vspace*{\fill}%
  \fi
  \egroup
  \else\closein15
  \includepdf[pages=-]{#1}%
  \fi
  \fi
  \fi
}

% Okolina za zahvale postavlja tekst nadesno tako da iznad teksta ima otprlike 70%
% praznog prostora u odnosu na ostatak do kraja stranice. \null-ove i \vskip-ove
% smo dodali tako da čak i kad je okolina prazna ista zauzima jednu stranicu.
\newenvironment{zahvale}
{%
  \clearpage
  \thispagestyle{empty}%
  \raggedleft
  \null\vskip 0pt plus 0.7fill\null\vskip 0pt\sl\null
}%
{%
  \vskip 0pt plus 0.3fill\null\vskip 0pt\newpage
}

% Dodatne naredbe od interesa
\newcommand{\engl}[1]{(engl.\@ \emph{#1})}
\newcommand{\itd}{itd.\@}
\newcommand{\npr}{npr.\@}
\newcommand{\hrv}[1]{(hrv.\@ \emph{#1})}
\newcommand{\etc}{etc.\@}
\newcommand{\eg}{e.g.\@}
\newcommand{\ie}{i.e.\@}

% Neki matematički operatori i funkcije uobičajeni kod nas
\def\CTFS{\mathop{\operator@font CTFS}\nolimits}
\def\CTFT{\mathop{\operator@font CTFT}\nolimits}
\def\DCTIII{\mathop{\operator@font DCT{\text{-}}III}\nolimits}
\def\DCTII{\mathop{\operator@font DCT{\text{-}}II}\nolimits}
\def\DCTIV{\mathop{\operator@font DCT{\text{-}}IV}\nolimits}
\def\DCTI{\mathop{\operator@font DCT{\text{-}}I}\nolimits}
\def\DCTVIII{\mathop{\operator@font DCT{\text{-}}VIII}\nolimits}
\def\DCTVII{\mathop{\operator@font DCT{\text{-}}VII}\nolimits}
\def\DCTVI{\mathop{\operator@font DCT{\text{-}}VI}\nolimits}
\def\DCTV{\mathop{\operator@font DCT{\text{-}}V}\nolimits}
\def\DCT{\mathop{\operator@font DCT}\nolimits}
\def\DFT{\mathop{\operator@font DFT}\nolimits}
\def\DSTIII{\mathop{\operator@font DST{\text{-}}III}\nolimits}
\def\DSTII{\mathop{\operator@font DST{\text{-}}II}\nolimits}
\def\DSTIV{\mathop{\operator@font DST{\text{-}}IV}\nolimits}
\def\DSTI{\mathop{\operator@font DST{\text{-}}I}\nolimits}
\def\DSTVIII{\mathop{\operator@font DST{\text{-}}VIII}\nolimits}
\def\DSTVII{\mathop{\operator@font DST{\text{-}}VII}\nolimits}
\def\DSTVI{\mathop{\operator@font DST{\text{-}}VI}\nolimits}
\def\DSTV{\mathop{\operator@font DST{\text{-}}V}\nolimits}
\def\DST{\mathop{\operator@font DST}\nolimits}
\def\DTFS{\mathop{\operator@font DTFS}\nolimits}
\def\DTFT{\mathop{\operator@font DTFT}\nolimits}
\def\ICTFS{\mathop{\operator@font ICTFS}\nolimits}
\def\ICTFT{\mathop{\operator@font ICTFT}\nolimits}
\def\IDCT{\mathop{\operator@font IDCT}\nolimits}
\def\IDFT{\mathop{\operator@font IDFT}\nolimits}
\def\IDST{\mathop{\operator@font IDST}\nolimits}
\def\IDTFS{\mathop{\operator@font IDTFS}\nolimits}
\def\IDTFT{\mathop{\operator@font IDTFT}\nolimits}
\def\MDCT{\mathop{\operator@font MDCT}\nolimits}
\def\arcctg{\mathop{\operator@font arcctg}\nolimits}
\def\arch{\mathop{\operator@font arch}\nolimits}
\def\arctg{\mathop{\operator@font arctg}\nolimits}
\def\arcth{\mathop{\operator@font arcth}\nolimits}
\def\arsh{\mathop{\operator@font arsh}\nolimits}
\def\arth{\mathop{\operator@font arth}\nolimits}
\def\ccnv#1{\mathbin{\ocircle\mkern-7mu\hbox to 0pt{\hss\raisebox{.08ex}{$\m@th\scriptstyle{#1}$}\hss}\mkern7mu}}
\def\ccnvN{\mathbin{\ocircle\mkern-7mu\raisebox{0.12ex}{\hbox to 0pt{\hss\scalebox{0.8}{$\m@th\scriptstyle{N}$}\hss}}\mkern7mu}}
\def\ccnvs#1{\mathbin{\ocircle\mkern-7mu\raisebox{0.24ex}{\hbox to 0pt{\hss\scalebox{0.9}{$\m@th\scriptscriptstyle{#1}$}\hss}}\mkern7mu}}
\def\ceil{\mathop{\operator@font ceil}\nolimits}
\def\ch{\mathop{\operator@font ch}\nolimits}
\def\comb{\mathop{\operator@font comb}\nolimits}
\def\ctg{\mathop{\operator@font ctg}\nolimits}
\def\cth{\mathop{\operator@font cth}\nolimits}
\def\diag{\mathop{\operator@font diag}\nolimits}
\def\dirac{\mathop{\delta}\nolimits}
\def\divg{\mathop{\operator@font div}\nolimits}
\def\dvacnv{\mathbin{{*}{*}}}
\def\erfc{\mathop{\operator@font erfc}\nolimits}
\def\erf{\mathop{\operator@font erf}\nolimits}
\def\fix{\mathop{\operator@font fix}\nolimits}
\def\floor{\mathop{\operator@font floor}\nolimits}
\def\grad{\mathop{\operator@font grad}\nolimits}
\def\imag{\mathop{\operator@font Im}\nolimits}
\def\ln{\mathop{\operator@font ln}\nolimits}
\def\mod{\mathop{\operator@font mod}\nolimits}
\def\rang{\mathop{\operator@font rang}\nolimits}
\def\real{\mathop{\operator@font Re}\nolimits}
\def\rect{\mathop{\operator@font rect}\nolimits}
\def\rot{\mathop{\operator@font rot}\nolimits}
\def\round{\mathop{\operator@font round}\nolimits}
\def\sgn{\mathop{\operator@font sgn}\nolimits}
\def\sh{\mathop{\operator@font sh}\nolimits}
\def\sign{\mathop{\operator@font sign}\nolimits}
\def\sinc{\mathop{\operator@font sinc}\nolimits}
\def\step{\mathop{\operator@font \mu}\nolimits}
\def\tg{\mathop{\operator@font tg}\nolimits}
\def\th{\mathop{\operator@font th}\nolimits}
\def\tri{\mathop{\operator@font tri}\nolimits}
\def\tr{\mathop{\operator@font tr}\nolimits}
\def\var{\mathop{\operator@font Var}\nolimits}
\def\cov{\mathop{\operator@font cov}\nolimits}
\def\rank{\mathop{\operator@font rank}\nolimits}
\def\uvrem{\nonscript\mskip-\medmuskip\mkern5mu
  \mathbin{\bullet\mkern-8mu-\mkern-9mu-\mkern-3mu\bigcirc}\penalty900\mkern5mu\nonscript\mskip-\medmuskip} 
\def\ufrek{\nonscript\mskip-\medmuskip\mkern5mu
  \mathbin{\bigcirc\mkern-7mu-\mkern-9mu-\mkern-4mu\bullet}\penalty900\mkern5mu\nonscript\mskip-\medmuskip}

% Oznake slika i tablica koriste manji font od normalnog teksta.
% U hrvatskom nakon broja slike i tablice dolazi točka jer se radi o rednom broju pa
% vizualno nije potrebna dvotočka za razdvajanje nego je dovoljan razmak.
% U engleskom ostavljamo dvotočku koja je zadana pa ništa ne treba mijenjati.
\if@hrvatski
\captionsetup[table]{labelsep=space,font=small}
\captionsetup[figure]{labelfont=bf,labelsep=space,font=small}
\else
\captionsetup[table]{font=small}
\captionsetup[figure]{labelfont=bf,font=small}
\fi

% Brojevi stranica su na vanjskoj margini dolje
\def\ps@plain{
  \let\@mkboth\@gobbletwo
  \let\@oddhead\@empty\let\@evenhead\@empty
  \def\@oddfoot{\hfil\thepage}%
  \def\@evenfoot{\thepage\hfil}}
\pagestyle{plain}

% Numeriranje stranica počinje od sadržaja. Da bi to postigli slično kao u klasi book
% definiramo mainmatter i backmatter naredbe koje redefiniraju numeriranje poglavlja
% i stranica. Numeriranje stranica započinje od mjesta u dokumentu na kojem zadamo
% \mainmatter, a riječ Privitak/Appendix se dodaje imenima poglavlja nakon mjesta u
% dokumentu na kojem zadamo \backmatter.
\newif\if@appendix\@appendixfalse
\newcommand\mainmatter{%
  \pagestyle{plain}%
  \cleardoublepage
  \@appendixfalse
  \pagenumbering{arabic}%
  \setcounter{page}{1}%
}
\newcommand\backmatter{%
  \pagestyle{plain}%
  \if@openright
    \cleardoublepage
  \else
    \clearpage
  \fi
  \@appendixtrue
  \setcounter{chapter}{0}%
  \setcounter{section}{0}%
  \gdef\@chapapp{\appendixname}%
  \gdef\thechapter{\@Alph\c@chapter}%
}

% Poglavlja su numerirana brojčano u tijelu rada te slovima u privitku.
% Imena poglavlja koriste boldane fontove počevši od veličine 18pt.
\def\arialpoglavlje{\arialbold{18}{19}}
\def\arialdio{\arialbold{16}{17}}
\def\arialpoddio{\arialbold{14}{15}}
\def\arialpodpoddio{\arialbold{12}{13}}
\def\@makechapterhead#1{%
  \vspace*{50\p@}%
  {\parindent \z@ \raggedright
    \ifnum \c@secnumdepth >\m@ne
      \if@appendix\arialpoglavlje\@chapapp\space\thechapter:\else\arialpoglavlje\thechapter\fi
    \fi
    \arialpoglavlje\@\hspace{1em}\parbox[t]{10cm}{#1}\par\nobreak
    \vskip 40\p@
  }}
\def\@makeschapterhead#1{%
  \vspace*{50\p@}%
  {\parindent \z@ \raggedright
    \interlinepenalty\@M
    \arialpoglavlje #1\par\nobreak
    \vskip 40\p@
  }}
\renewcommand\section{%
  \@startsection {section}{1}{\z@}%
  {-3.5ex \@plus -1ex \@minus -.2ex}%
  {2.3ex \@plus.2ex}%
  {\arialdio}%
}
\renewcommand\subsection{%
  \@startsection{subsection}{2}{\z@}%
  {-3.25ex\@plus -1ex \@minus -.2ex}%
  {1.5ex \@plus .2ex}%
  {\arialpoddio}%
}
\renewcommand\subsubsection{%
  \@startsection{subsubsection}{3}{\z@}%
  {-3.25ex\@plus -1ex \@minus -.2ex}%
  {1.5ex \@plus .2ex}%
  {\arialpodpoddio}%
}
\def\@chapter[#1]#2{\ifnum \c@secnumdepth >\m@ne
  \refstepcounter{chapter}%
  \typeout{\@chapapp\space\thechapter.}%
  \addcontentsline{toc}{chapter}%
  {\protect\numberline{\thechapter\if@appendix:\fi}#1}%
  \else
  \addcontentsline{toc}{chapter}{#1}%
  \fi
  \chaptermark{#1}%
  \addtocontents{lof}{\protect\addvspace{10\p@}}%
  \addtocontents{lot}{\protect\addvspace{10\p@}}%
  \if@twocolumn
  \@topnewpage[\@makechapterhead{#2}]%
  \else
  \@makechapterhead{#2}%
  \@afterheading
  \fi}

% Naredbe za slaganje sažetka i ključnih riječi na hrvatskom i na engleskom
\renewenvironment{abstract}{%
  \otherlanguage{english}%
  \if@seminar\relax\else\chapter*{\abstractname}\fi%
  \addcontentsline{toc}{chapter}{\abstractname}%
  \begin{center}%
    {\arialbold{14}{15} \@title}\par
    \vskip 6pt plus 2pt minus 2pt%
    {\arial{14}{15} \@author}\par
    \vskip 8pt plus 2pt minus 2pt%
    \if@seminar\textsl{\abstractname}\vskip 8pt plus 2pt minus 2pt\fi%
  \end{center}%
  \everypar{}%
}
{\endotherlanguage}

\newenvironment{keywords}
{
  \otherlanguage{english}%
  \vskip 12pt plus 2pt minus 2pt%
  \noindent\textbf{Keywords:\hskip 0.5em}
}
{\endotherlanguage}

\newenvironment{sazetak}{%
  \otherlanguage{croatian}%
  \if@seminar\relax\else\chapter*{\abstractname}\fi%
  \addcontentsline{toc}{chapter}{\abstractname}%
  \begin{center}%
    {\arialbold{14}{15} \@naslov}\par
    \vskip 6pt plus 2pt minus 2pt%
    {\arial{14}{15} \@autor}\par
    \vskip 8pt plus 2pt minus 2pt%
    \if@seminar\textsl{\abstractname}\vskip 8pt plus 2pt minus 2pt\fi%
  \end{center}%
  \everypar{}%
}
{\endotherlanguage}

\newenvironment{kljucnerijeci}
{
  \otherlanguage{croatian}%
  \vskip 12pt plus 2pt minus 2pt%
  \noindent\textbf{Klju\v{c}ne rije\v{c}i:\hskip 0.5em}
}
{\endotherlanguage}

% U sadržaju je ime poglavlja povezano točkicama s brojem poglavlja.
\renewcommand*\l@chapter[2]{%
  \ifnum \c@tocdepth >\m@ne
  \addpenalty{-\@highpenalty}%
  \vskip 1.0em \@plus\p@
  \setlength\@tempdima{1.5em}%
  \begingroup
  \parindent \z@ \rightskip \@pnumwidth
  \parfillskip -\@pnumwidth
  \leavevmode \bfseries
  \advance\leftskip\@tempdima
  \hskip -\leftskip
  #1\nobreak\leaders\hbox{$\m@th
    \mkern \@dotsep mu\hbox{.}\mkern \@dotsep
    mu$}\hfil
  \nobreak\hb@xt@\@pnumwidth{\hss #2%
    \kern-\p@\kern\p@}\par
  \penalty\@highpenalty
  \endgroup
  \fi
}

% PDF datoteka za učitavanje na FERWeb mora biti PDF/A.
% Za to koristimo pdfx paket za koji moramo pripremiti i datoteku s podacima.
% Podatke o naslovu i autoru preuzimamo iz standardnih \author i \title naredbi,
% no iste se mogu redefinirati preko doljedefiniranih inačica s PDF-ovm u imenu.
\def\PDFTitle#1{\gdef\@PDFTitle{#1}}
\def\PDFAuthor#1{\gdef\@PDFAuthor{#1}}
\def\PDFLanguage#1{\gdef\@PDFLanguage{#1}}
\def\PDFSubject#1{\gdef\@PDFSubject{#1}}
\def\PDFKeywords#1{\gdef\@PDFKeywords{#1}}

\gdef\@PDFTitle{\@title}
\gdef\@PDFAuthor{\@author}
\gdef\@PDFLanguage{\if@hrvatski hr-HR\else en-US\fi}
\gdef\@PDFSubject{}
\gdef\@PDFKeywords{}
  
\if@upload%
\usepackage{newfile}
\usepackage{colorprofiles}
\usepackage[a-2b,mathxmp,latxmp]{pdfx}
\def\writeoutPDFmetadata{
  \newoutputstream{PDFmetadata}
  \openoutputfile{\jobname.xmpdata}{PDFmetadata}
  \addtostream{PDFmetadata}{\protect\Title{\@PDFTitle}}%
  \addtostream{PDFmetadata}{\protect\Author{\@PDFAuthor}}%
  \addtostream{PDFmetadata}{\protect\Language{\@PDFLanguage}}%
  \addtostream{PDFmetadata}{\protect\Subject{\@PDFSubject}}%
  \addtostream{PDFmetadata}{\protect\Keywords{\@PDFKeywords}}%
  \closeoutputstream{PDFmetadata}
}
\AtEndDocument{\writeoutPDFmetadata}
\fi

% Ispiši u .log datoteku sve učitane pakete i to redom koji se učitavaju.
\listfiles


% Ovisno o jeziku treba riješiti problem točaka. Za engleski koristimo standardnu
% klasu report bez izmjena, no u hrvatskom iza rednog broja dolazi točka što znači
% da moramo ispraviti numeriranje poglavlja, slika i tablica.
\if@hrvatski

% Brojevi poglavlja/dijelova/paragrafa imaju točku na kraju.
\renewcommand\thechapter{\@arabic\c@chapter.}
\renewcommand\thesection{\thechapter\@arabic\c@section.}
\renewcommand\thesubsection{\thesection\@arabic\c@subsection.}
\renewcommand\thesubsubsection{\thesubsection\@arabic\c@subsubsection.}
\renewcommand\theparagraph{\thesubsubsection\@arabic\c@paragraph.}
\renewcommand\thesubparagraph{\theparagraph\@arabic\c@subparagraph.}

% Dodane točke treba ukloniti na drugim mjestima gdje korisitmo brojeve poglavlja.
% Osim toga numeracija slika i tablica završava točkom.
% Brojevi jednadžbi su standardno u zagradama pa ne dodajemo završnu točku.
\renewcommand\theequation{\ifnum \c@chapter>\z@ \thechapter\@\fi \@arabic\c@equation}
\renewcommand\thefigure{\ifnum \c@chapter>\z@ \thechapter\@\fi \@arabic\c@figure.}
\renewcommand\thetable{\ifnum \c@chapter>\z@ \thechapter\@\fi \@arabic\c@table.}

\fi


% Dodavanje točke nakon rednog broja slike i tablice uzrokuje problem kada se referenca
% na sliku ili na tablicu koristi na kraju rečenice jer dobivamo dvostruku točku.
% Zato redefiniramo naredbu \ref tako da se to automatski ispravi.

% Pomoćna naredba za uklanjanje sljedećeg znaka u ulazu.
% Kod preuzet s https://tex.stackexchange.com/questions/72827/consume-absorb-a-token
\newcommand{\removeifnextchar}[3]{%
  \begingroup
  \ltx@LocToksA{\endgroup#2}%
  \ltx@LocToksB{\endgroup#3}%
  \ltx@ifnextchar@nospace{#1}{%
    \def\next{\the\ltx@LocToksA}%
    \afterassignment\next
    \let\scratch= %
  }{%
    \the\ltx@LocToksB
  }%
}

% Redefiniramo naredbu za referenciranje tako da se dobiva uvjetno ponašanje
% ovisno o sljedećem znaku iza naredbe kako slijedi:
% 1) ako je sljedeći znak točka onda tu točku brišemo,
% 2) u ostalim slučajevima ne diramo referencu.
% Zbog ostalih paketa koji se učitavaju ovaj niz naredbi dodajemo u listu naredbi
% koje se izvršavaju tek prilikom poziva \begin{document}.
% Stara \ref naredba je snimljena kao \old@ref.
\if@hrvatski
\AfterEndPreamble{
  % Spremi staru ref naredbu
  \LetLtxMacro{\old@ref}{\ref}%
  % Redefiniraj ref naredbu
  \renewcommand{\ref}[1]{%
    \removeifnextchar{.}% Ukloni točku ako slijedi
    {\old@ref{#1}}% Našli smo i uklonili točku pa ide referenca sa točkom
    {\old@ref{#1}\@}% Za sve ostale slučajeve ide normalna referenca, \@ je potreban radi korekcije razmaka
  }%
}
\fi