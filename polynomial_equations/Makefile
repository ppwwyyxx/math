TARGET=polynomial_equations
TEX=xelatex -shell-escape
BIBTEX=bibtex

all: view


rebuild  output/$(TARGET).pdf: *.tex *.bib output
	cd output && rm -f *.tex *.bib && ln -s ../*.tex ../*.bib .
	cd output && $(TEX) $(TARGET).tex && $(BIBTEX) $(TARGET).aux && \
		$(TEX) $(TARGET).tex



output:
	mkdir output
	cd output && rm -f res && ln -s ../res .

view: output/$(TARGET).pdf
	evince output/$(TARGET).pdf &

clean:
	rm -rf output

dist: output/$(TARGET).pdf
	rm -rf paper
	mkdir paper
	cp output/$(TARGET).pdf paper/
	cp -r screenshots paper/
	7z a -tzip paper.zip paper
	rm -rf paper

.PHONY: all view clean rebuild dist
