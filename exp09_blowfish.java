import java.util.Scanner;
import java.security.MessageDigest;
import javax.crypto.spec.SecretKeySpec;
import javax.crypto.Cipher;


public class exp09_blowfish{
    public static void main(String args[]){

        try {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the message: ");
            String messsage = sc.nextLine();

            System.out.print("Enter the key: ");
            String keyString = sc.nextLine();
            MessageDigest mDigest = MessageDigest.getInstance("SHA-1");
            byte keyBytes[] = mDigest.digest(keyString.getBytes());
            SecretKeySpec blowfishKey = new SecretKeySpec(keyBytes, "Blowfish");

            Cipher blowfishCipher = Cipher.getInstance("Blowfish");
            blowfishCipher.init(Cipher.ENCRYPT_MODE, blowfishKey);
            byte ciphertextBytes[] = blowfishCipher.doFinal(messsage.getBytes());

            System.out.print("Ciphertext is: ");
            for (byte cipher : ciphertextBytes){
                System.out.print(String.format("%02X", cipher));
            }
            System.out.println();

            blowfishCipher.init(Cipher.DECRYPT_MODE, blowfishKey);
            byte plaintextBytes[] = blowfishCipher.doFinal(ciphertextBytes);

            System.out.println("Plaintext is: "+ new String(plaintextBytes));
        }
        catch (Exception e){

        }


    }
}