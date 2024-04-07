@echo off
cd Libreria\src\utili
javac Utl.java
jar cvfm Lib.jar Utl.class
java -jar Lib.jar


