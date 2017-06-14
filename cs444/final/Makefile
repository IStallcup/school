all: stallcui_writing3.pdf stallcui_writing2.pdf
	
stallcui_writing3.dvi: stallcui_writing3.tex
	latex stallcui_writing3.tex
	bibtex stallcui_writing3.aux
	latex stallcui_writing3.tex
	latex stallcui_writing3.tex

stallcui_writing3.ps: stallcui_writing3.dvi
	dvips stallcui_writing3.dvi

stallcui_writing3.pdf: stallcui_writing3.ps
	ps2pdf stallcui_writing3.ps

stallcui_writing2.dvi: stallcui_writing2.tex
	latex stallcui_writing2.tex
	bibtex stallcui_writing2.aux
	latex stallcui_writing2.tex
	latex stallcui_writing2.tex

stallcui_writing2.ps: stallcui_writing2.dvi
	dvips stallcui_writing2.dvi

stallcui_writing2.pdf: stallcui_writing2.ps
	ps2pdf stallcui_writing2.ps

clean:
	rm -f *.dvi *.aux *.ps
