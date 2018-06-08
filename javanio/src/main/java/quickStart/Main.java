package  quickStart;

import java.io.File;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println ( new File ( "." ).getAbsolutePath ());
        System.out.println ( Main.class.getResource("/").getPath());
        //RandomAccessFile aFile = new RandomAccessFile ( "./target/classes/nio-data.txt","rw" );
        RandomAccessFile aFile = new RandomAccessFile ( Main.class.getResource ( "/nio-data.txt" ).getFile (),"rw" );
        FileChannel inChannel = aFile.getChannel ();
        ByteBuffer buf = ByteBuffer.allocate ( 48 );
        int bytesRead = inChannel.read ( buf );
        System.out.println ( bytesRead + " returned from inChannel" );
        while (bytesRead != -1) {
            System.out.println ( "\nRead " + bytesRead );
            buf.flip ();
            while (buf.hasRemaining ()) {
               System.out.print ( (char) buf.get () );
            }
            buf.clear ();
            bytesRead = inChannel.read ( buf );
        }
        aFile.close ();
    }
}
