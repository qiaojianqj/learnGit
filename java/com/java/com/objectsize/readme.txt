1. ObjectShallowSize.java + META-INF/MANIFEST.MF
2. javac com\objectsize\ObjectShallowSize.java
3. jar cvfm com\objectsize\java-agent-sizeof.jar com\objectsize\META-INF/MANIFEST.MF  .
4. javac com\objectsize\Main.java
5. java -javaagent:com\objectsize\java-agent-sizeof.jar com\objectsize\Main