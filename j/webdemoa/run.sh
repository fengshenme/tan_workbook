#!/bin/bash



if [ $1 == "i" ]; then
"H:/apache-maven-3.6.3/bin/mvn.cmd" install -f "H:\sharecode\java\2day\webdemoa\pom.xml"
echo "-----------------------------------------------------"
java -jar target/webdemoa-0.0.1.jar
elif [ $1 == "c" ]; then
"H:/apache-maven-3.6.3/bin/mvn" clean -f "H:\sharecode\java\2day\webdemoa\pom.xml"
fi
