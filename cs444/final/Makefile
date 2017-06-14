all: stallcui_writing1.pdf stallcui_writing2.pdf stallcui_writing3.pdf stallcui_writing_final.pdf

extra:
	rm -f *.dvi *.aux *.ps *.log *.blg *.out *.bbl *.pdf

clean:
	rm -f *.dvi *.aux *.ps *.log *.blg *.out *.bbl 

stallcui_writing_final.pdf: stallcui_writing_final.ps
	ps2pdf stallcui_writing_final.ps

stallcui_writing_final.ps: stallcui_writing_final.dvi
	dvips stallcui_writing_final.dvi

stallcui_writing_final.dvi:
	latex stallcui_writing_final.tex
	bibtex stallcui_writing_final.aux
	latex stallcui_writing_final.tex
	latex stallcui_writing_final.tex

stallcui_writing1.pdf: stallcui_writing1.ps
	ps2pdf stallcui_writing1.ps

stallcui_writing1.ps: stallcui_writing1.dvi
	dvips stallcui_writing1.dvi

stallcui_writing1.dvi:
	latex stallcui_writing1.tex
	bibtex stallcui_writing1.aux
	latex stallcui_writing1.tex
	latex stallcui_writing1.tex

stallcui_writing2.pdf: stallcui_writing2.ps
	ps2pdf stallcui_writing2.ps

stallcui_writing2.ps: stallcui_writing2.dvi
	dvips stallcui_writing2.dvi

stallcui_writing2.dvi:
	latex stallcui_writing2.tex
	bibtex stallcui_writing2.aux
	latex stallcui_writing2.tex
	latex stallcui_writing2.tex

stallcui_writing3.pdf: stallcui_writing3.ps
	ps2pdf stallcui_writing3.ps

stallcui_writing3.ps: stallcui_writing3.dvi
	dvips stallcui_writing3.dvi

stallcui_writing3.dvi:
	latex stallcui_writing3.tex
	bibtex stallcui_writing3.aux
	latex stallcui_writing3.tex
	latex stallcui_writing3.tex
