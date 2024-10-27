import java.util.Scanner;
import java.security.MessageDigest;
import javax.crypto.SecretKeyFactory;
import javax.crypto.SecretKey;
import javax.crypto.spec.DESKeySpec;
import javax.crypto.Cipher;

public class exp6_des{
    public static void main(String args[]){

        try {
            Scanner sc = new Scanner(System.in);

            System.out.print("Enter the message: ");
            String message = sc.nextLine();

            System.out.print("Enter the key: ");
            String keyString = sc.nextLine();
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            byte hashBytes[] = md.digest(keyString.getBytes());
            SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
            SecretKey desKey = keyFactory.generateSecret(new DESKeySpec(hashBytes));

            Cipher desCipher = Cipher.getInstance("DES");
            desCipher.init(Cipher.ENCRYPT_MODE, desKey);
            byte ciphertextBytes[] = desCipher.doFinal(message.getBytes());
            System.out.print("Ciphertext is: ");
            for (byte cipher : ciphertextBytes){
                System.out.print(String.format("%02X", cipher));
            }
            System.out.println();

            desCipher.init(Cipher.DECRYPT_MODE, desKey);
            byte plaintextBytes[] = desCipher.doFinal(ciphertextBytes);
            System.out.println("Plaintext is: "+new String(plaintextBytes));

            sc.close();
        }
        catch (Exception e){
            e.printStackTrace();
        }


    }
}