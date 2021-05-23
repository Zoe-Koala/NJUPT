
<html>
    <head>
        <title>This is output</title>
    </head>
 
    <body>
        <?php
            $name = $_POST["name"];
            $address = $_POST["address"];
            $zip = $_POST["zip"];
            $web_t = $_POST["web_t"];
            $math = $_POST["math"];
            $os = $_POST["os"];
            $matrix = $_POST["matrix"];
            $payment = $_POST["payment"];
            
            if($web_t == "") $web_t = 0;
            if($math == "") $math = 0;
            if($os == "") $os = 0;
            if($matrix == "") $matrix = 0;
    
            $web_t_cost = 5.0*$web_t;
            $math_cost = 6.2*$math;
            $os_cost = 10*$os;
            $matrix_cost = 7.8*$matrix;
            $total_num = $web_t+$math+$os+$matrix;
            $total_price=$web_t_cost+$math_cost+$os_cost+$matrix_cost;
        ?>
        <?php
            printf("Your name:$name <br/> your address:$address <br/> Your zip:$zip<br/>")
        ?>
        <p/>
        <table border = "border">
            <tr>
                <th>book</th>
                <th>publisher</th>
                <th>price</th>
                <th>quantity</th>
                <th>total cost</th>
            </tr>
        <?php if($web_t != 0) { ?>
            <tr>
                <td>Web technology</td>
                <td>Springer press</td>
                <td>$5.0</td>
                <td>
                    <?php print($web_t);?>
                </td>
                <td>
                    <?php printf("$ %4.2f", $web_t_cost);?>
                </td>
            </tr>
        <?php } ?>
        <?php if($math != 0) { ?>
            <tr>
                <td>mathematics</td>
                <td>ACM press</td>
                <td>$6.2</td>
                <td>
                    <?php print($math);?>
                </td>
                <td>
                    <?php printf("$ %4.2f", $math_cost); ?>
                </td>
            </tr>
        <?php } ?>
        <?php if($os != 0) { ?>
            <tr>
                <td>Theory of matrix</td>
                <td>High education press</td>
                <td>$10</td>
                <td><?php print($os);?> </td>
                <td>
                    <?php printf("$ %4.2f", $os_cost); ?>
                </td>
            </tr>
        <?php } ?>
        <?php if($matrix !=0) { ?>
            <tr>
                <td>Theory of matrix</td>
                <td>High education press</td>
                <td>$7.8</td>
                <td><?php print($matrix);?> </td>
                <td>
                    <?php printf("$ %4.2f", $matrix_cost); ?>
                </td>
            </tr>
        <?php } ?>
        </table>
    
        <?php printf("%s has bought %d books<br/>", $name, $total_num) ?>
        <?php printf("%s paid %.4f <br/>", $name, $total_price) ?>
        <?php printf("paid by %s <br/>", $payment) ?>
    
        <?php
        // $file = fopen("customer.txt", "a");
        // fwrite($file, "$name has bought $total_num books\r\n");
        // fwrite($file, "$name paid $total_price\r\n");
        // fwrite($file, "paid by $payment\r\n");
        ?>
    </body>
</html>