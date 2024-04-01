package symmetric_key;

public class DES {
    private String key;
    private String message;

    private String[] keys = new String[16];

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public static void main(String[] args) {

    }

}
