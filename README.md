# TV-B-Boy
Use your GBC as an universal remote like the TV-B-Gone

**This project is still under developpement, at this time the IR register hasn't been set
EDIT : A rewrite from scratch in GBZ80 Assembly is necessary because GBDK doesn't include the IR function sadly :(**

## How to compile it
1. Clone the git
2. Put the content of the include folder on your include folder located in your GDK copy
3. Compile it "**lcc -Wl-yp0x143=0x80 -o TVBB.gbc TV-B-Boy.c**"
