# Predložak za diplomske i završne radove

Ovaj repozitorij sadrži predložak za pisanje diplomski i završnih radova u LaTeX-u.

## Diplomski rad

Klasa koja se koristi je `fer.cls` s opcijom `diplomskirad`. Ogledni minimalni dokument ima strukturu:

    \documentclass[diplomskirad]{fer}
    \title{Naslov na engleskom jeziku}
    \naslov{Naslov na hrvatskom jeziku}
    \brojrada{1234}
    \author{Ime Prezime}
    \date{June, 2021}
    \datum{lipanj, 2021.}
    \begin{document}
    \maketitle
    \zadatak{filename.pdf}
    \begin{zahvale}
      zahvale
    \end{zahvale}
    \mainmatter
    \tableofcontents
    % TEKST RADA
    \bibliography{literatura}
    \begin{sazetak}
      sažetak na hrvatskom
    \end{sazetak}
    \begin{kljucnerijeci}
      ključne riječi na hrvatskom
    \end{kljucnerijeci}
    \begin{abstract}
      abstract in English
    \end{abstract}
    \begin{keywords}
      keywords in English
    \end{keywords}
    \end{document}

Osim klase potrebna je i pripadna .bst datoteka. Standardno se koristi `fer_IEEEtran_HR.bst` za brojčano citiranje na hrvatskom, no ako se želi koristiti citiranje (autor, godina) onda se mora zadati opcija `authoryear` te se koristi `fer_plainnat_HR.bst`.

Dodatna opcija od interesa je `upload` koja iz generiranog PDF dokumenta isključuje naslovnicu i tekst zadatka tako da je generirani dokument pripremljen za učitavanje na FERWeb:

    \documentclass[diplomskirad,upload]{fer}

## Završni rad

Klasa koja se koristi je `fer.cls` s opcijom `zavrsnirad`. Sve ostalo je isto kao i za diplomski rad.

# Thesis Template

This repository contains LaTeX template for writing master and bachelor theses at University of Zagreb Faculty of Electrical Engineering and Computing.

## Master Thesis

The class to be used is `fer.cls` with the option `masterthesis`. An example minimal document is:

    \documentclass[masterthesis]{fer}
    \title{Title in English}
    \naslov{Title in Croatian}
    \brojrada{1234} % Thesis number
    \author{Name Surname}
    \date{June, 2021}
    \datum{lipanj, 2021.}
    \begin{document}
    \maketitle
    \zadatak{filename.pdf} % PDF document with the thesis assignment
    \begin{zahvale}
      acknowledgment
    \end{zahvale}
    \mainmatter
    \tableofcontents
    % THESIS BODY
    \bibliography{references}
    \begin{abstract}
      abstract in English
    \end{abstract}
    \begin{keywords}
      keywords in English
    \end{keywords}
    \begin{sazetak}
      sažetak na hrvatskom
    \end{sazetak}
    \begin{kljucnerijeci}
      ključne riječi na hrvatskom
    \end{kljucnerijeci}    
    \end{document}

Besides the class you also need the approriate .bst file. The standard one is `fer_IEEEtran_EN.bst` for numerical quoting style, however, if (author,year) is to be used then give the option `authoryear` to the class and use `fer_plainnat_EN.bst`.

Additional option of interest is `upload` which removes the titlepage and thesis assignemt pages so the generated PDF may be uploaded to FERWeb:

    \documentclass[masterthesis,upload]{fer}

## Bachelor Thesis

The class to be used is `fer.cls` with the option `bachelorthesis`. Everything else is the same as for the master thesis.
