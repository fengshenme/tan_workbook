package tan.wei.feng.exception;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

/**
 * 自定义的异常
 * @author 锋什么
 *
 */
@ResponseStatus(HttpStatus.EXPECTATION_FAILED)
public class UserLoginException extends RuntimeException {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public UserLoginException(String message) {
        super(message);
    }

    public UserLoginException(String message, Throwable cause) {
        super(message, cause);
    }

}