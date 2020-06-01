package rock_paper_scissors;

//工具类
public class Tool {
    public static Result judge(Select A, Select B) {//胜负判断
        if (A.equals(B)) {
            return Result.ALL_WIN;
        } else if (
                (A.equals(Select.ROCK) && B.equals(Select.SCISSORS)) ||
                        (A.equals(Select.SCISSORS) && B.equals(Select.PAPER)) ||
                        (A.equals(Select.PAPER) && B.equals(Select.ROCK))) {
            return Result.LEFT_WIN;
        } else {
            return Result.RIGHT_WIN;
        }
    }
}
