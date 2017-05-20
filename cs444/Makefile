all: stallcui_writing2.pdf

stallcui_writing2.dvi: stallcui_writing2.tex
	latex stallcui_writing2.tex
	bibtex stallcui_writing2.tex
	latex stallcui_writing2.tex
	latex stallcui_writing2.tex

stallcui_writing2.ps: stallcui_writing2.dvi
	dvips stallcui_writing2.dvi

stallcui_writing2.pdf: stallcui_writing2.ps
	ps2pdf stallcui_writing2.ps
