import java.io.*;
import java.net.*;

class Client
{
	public static void main(String args[])throws IOException
	{
	
		String str1=" ",str2=" "; //one string for sending the data one for receiving the data..
		Socket s1=new Socket("localhost",6676);//ceating client socket with ip address and port number
		System.out.println("Connection Established");
		
		DataOutputStream dout=new DataOutputStream(s1.getOutputStream());//this is for sending the data from client to server
		DataInputStream din=new DataInputStream(s1.getInputStream());//this is for receiving the data from the server
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));//for taking input from user
		while(true)
		{
			//client sending message to the server
			System.out.print("Client msg:");
			str1=br.readLine();
			dout.writeUTF(str1);
			if(str1.equals("stop"))
				break;
			//accepting String from server and display 
			str2=din.readUTF();
			System.out.println("server says:"+str2);
			
			
		}
		dout.close();
		din.close();
		s1.close();
		
	}
}
