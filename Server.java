import java.io.*;
import java.net.*;

 public class Server
{
	public static void main(String args[]) throws Exception
	{
		String str1="",str2="";//one for reading and one for writing data
		ServerSocket s2=new ServerSocket(6676);//creating server socket with a port number
		Socket s=s2.accept();
		System.out.println("Connection Established");
		
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());//acceptig through the client side socket
		DataInputStream din=new DataInputStream(s.getInputStream());
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		while(true)
		{
		//server accepting message from client
			str1=din.readUTF();
			System.out.println("Client says:"+str1);
		
		//server sending message to the client
			System.out.print("Server msg:");
			str2=br.readLine();
			dout.writeUTF(str2);
			
			if(str1.equals("Stop"))
			 break;
		}
		dout.close();
		din.close();
		s2.close();
		s.close();
	}
}	

