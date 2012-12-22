TARGET=report
TEX=xelatex -shell-escape -output-directory=output
BIBTEX=bibtex
READER=mupdf

all: view

rebuild output/$(TARGET).pdf: *.tex *.bib output
	$(TEX) $(TARGET) && cd output && ln ../*.bib ./ -f && $(BIBTEX) $(TARGET) 

output: 
	mkdir output
	cd output && rm -f res && ln -s ../res .

view: output/$(TARGET).pdf
	$(READER) output/$(TARGET).pdf &

clean:
	rm *.pyg
	rm -rf output
	rm $(TARGET).pdf

# compile twice to get cross reference right
final : *.tex *.bib output
	$(TEX) $(TARGET) && cd output && ln ../*.bib ./ -f && $(BIBTEX) $(TARGET) 
	$(TEX) $(TARGET)

count:
	@word_count *.tex

dist: output/$(TARGET).pdf
	rm -rf paper
	mkdir paper
	cp output/$(TARGET).pdf paper/
	cp -r screenshots paper/
	7z a -tzip paper.zip paper
	rm -rf paper

.PHONY: all view clean rebuild dist
