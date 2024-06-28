import java.io.*;
import java.net.*;
public class server2{
public static void main(String[] args ) throws IOException{
         ServerSocket ss =new ServerSocket(4999);
         Socket s= ss.accept();
         System.out.println("client connected");

        InputStreamReader in = new InputStreamReader(s.getInputStream());
        BufferedReader bf =new BufferedReader(in);
        String str=bf.readLine();
        System.out.println("Client: "+str);    
       
        PrintWriter pr= new PrintWriter(s.getOutputStream());
        pr.println("Is it Working");
        pr.flush();
}
}