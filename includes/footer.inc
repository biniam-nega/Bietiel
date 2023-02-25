<!-- search modal -->
<div id="search_modal" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('search_modal').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
        <h2 class="w3-wide">Search</h2><hr/>
        <form action="home.php" method="get">
          <p>
            <input name="search" class="w3-input" type="text" required placeholder="Search for books, tutorials, manuals and authors...">
          </p>
          <button type="submit" class="w3-button w3-padding-large w3-red w3-margin-bottom w3-right" >Search</button>
        </form>
      </div>
    </div>
</div>

<div class="we-container w3-center">
  <div class="w3-container w3-black w3-center w3-opacity w3-padding-64 w3-margin-top">
      <h1 class="w3-margin w3-xlarge">
      <?php
      $verses_query = perform_query_return($mysql, "select * from verse", "all");
      $random = rand(0, $verses_query[0] - 1);
      $counter = 0;
      $verse = "";
      while($verses = mysqli_fetch_array($verses_query[1])){
        if ($counter == $random){
          $verse = $verses['verse_text'];
          break;
        }
        $counter ++;
      }
      ?>
      ጥቕሲ: "<?php echo $verse; ?>"</h1>
  </div>

  <!-- Footer -->
  <footer class="w3-container w3-padding-64 w3-center w3-opacity">  
   <p>A Biniam Nega production</p>
  </footer>

  <script>
// Accordion 
function worldcategory() {
  var x = document.getElementById("worldcategory");
  if (x.className.indexOf("w3-show") == -1) {
    x.className += " w3-show";
  } 
  else {
    x.className = x.className.replace(" w3-show", "");
  }
}

function spiritualcategory() {
  var x = document.getElementById("spiritualcategory");
  if (x.className.indexOf("w3-show") == -1) {
    x.className += " w3-show";
  } 
  else {
    x.className = x.className.replace(" w3-show", "");
  }
}


// Open and close sidebar
function sidebar_open() {
  document.getElementById("mySidebar").style.display = "block";
  document.getElementById("myOverlay").style.display = "block";
}
 
function sidebar_close() {
  document.getElementById("mySidebar").style.display = "none";
  document.getElementById("myOverlay").style.display = "none";
}
</script>
<?php if($page_type != 'admin'){ ?>
<!-- feedback Modal -->
  <div id="feedback" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom" style="">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('feedback').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
        <h2 class="w3-wide">Feedback</h2><hr/>
        <p>Here in Bietiel Digital Library, we appreciate any thoughts or suggestions you can give us.</p>
        <p><input class="w3-input" type="text" required placeholder="Name"></p>
        <p><textarea class="w3-input" type="text" placeholder="Write your suggestion here" required style="width: 100%"></textarea></p>
        <button type="button" class="w3-button w3-padding-large w3-red w3-margin-bottom" onclick="document.getElementById('feedback').style.display='none'">Submit suggestion</button>
      </div>
    </div>
  </div>

<!-- admin_login modal -->
<div id="admin_login" class="w3-modal" <?php if ($tried_to_login){ if ($info_error){ echo "style=\"display:block;\""; } } ?>>
  <div class="w3-modal-content w3-animate-zoom">
    <div class="w3-container w3-white w3-center">
      <a onclick="document.getElementById('admin_login').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
      <h2 class="w3-wide">Admin Login</h2><hr/>
      <form action="" method="post">
        <div class="w3-section">
          <label for="username" class="w3-left"><b>Username</b></label>
          <input class="w3-input w3-margin-bottom" required type="text" placeholder="Enter Username..." name="username" id="username">
          <label for="password" class="w3-left"><b>Password</b></label>
          <input class="w3-input" type="password" required placeholder="Enter Password..." name="password" id="password">
          
          <?php
          if($tried_to_login){
            if($info_error){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>The username and password you entered doesn't exist</p>
          </div>
          <?php
            }
          }
          ?>
          <div class="w3-center">
            <button type="submit" class="w3-button w3-green w3-section" name="login_button">Login</button>
            <button type="reset" class="w3-button w3-red w3-section">Reset</button>
          </div>
        </div>
      </form>
    </div>
  </div>
</div>
<?php } ?>

<?php if($page_type == 'admin'){ ?>
<!-- upload Modal -->
  <div id="upload_content" class="w3-modal" <?php if ($tried_to_upload){ if (!$uploaded_successfully){ echo "style=\"display:block;\""; } } ?>>
  <div class="w3-modal-content w3-animate-zoom">
    <div class="w3-container w3-white w3-center">
      <a onclick="document.getElementById('upload_content').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
      <h2 class="w3-wide">Upload book</h2><hr/>
      <form action="" method="post" enctype="multipart/form-data">
        <div class="w3-section">
          <label for="file" class="w3-left">መጽሓፍ ምረጽ</label>
          <input type="file" id="filename" name="filename" class="w3-input w3-margin-bottom" required />
          <?php
          if($tried_to_upload){
            if($unsupported_file){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Unsuported file type (supported - .pdf, .epub)</p>
          </div>
          <?php
            }
          }
          ?>

          <label for="cover_pic" class="w3-left">ስእሊ ምረጽ</label>
          <input type="file" id="cover_pic" name="cover_pic" class="w3-input w3-margin-bottom" />
          <?php
          if($tried_to_upload){
            if($unsupported_cover_pic){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Unsuported file type (supported - .png, .jpg, .gif)</p>
          </div>
          <?php
            }
          }
          ?>

          <input class="w3-input w3-margin-bottom" required type="text" placeholder="ኣርእስቲ..." name="title" id="title" value="<?php if($tried_to_upload){echo $title;} ?>">

          <input class="w3-input w3-margin-bottom" required type="text" placeholder="ጸሓፋይ..." name="author" id="author" value="<?php if($tried_to_upload){echo $author;} ?>">

          <textarea class="w3-input w3-margin-bottom" required name="description" id="description" placeholder="መብርሂ..." ><?php if($tried_to_upload){echo $desc;} ?></textarea>

          <label for="language" class="w3-left"><b>ቋንቋ</b></label>
          <input type="radio" name="language" value="tig" checked /> ትግርኛ
          <input type="radio" name="language" value="eng" /> English <br/><br/>

          <label for="category" class="w3-left"><b>ዓይነት</b></label>
          <input type="radio" name="category" value="spiritual" onclick="document.getElementById('world_dropdown').style.display='none';document.getElementById('spiritual_dropdown').style.display='block'; " checked> መንፈሳዊ
          <input type="radio" name="category" value="world" onclick="document.getElementById('world_dropdown').style.display='block';document.getElementById('spiritual_dropdown').style.display='none'; "> ዓለማዊ
          <select class="w3-input" id="spiritual_dropdown" name="category">
            <?php
            foreach($categories['spiritual'] as $name => $link){
            ?>
            <option value="<?php echo $link; ?>" style="width: 100px;"><?php echo $name; ?></option>
            <?php
            } ?>
          </select>
          <select class="w3-input" id="world_dropdown" name="category" style="display: none">
            <?php
            foreach($categories['world'] as $name => $link){
            ?>
            <option value="<?php echo $link; ?>" style="width: 100px;"><?php echo $name; ?></option>
            <?php
            } ?>
          </select>
          <div class="w3-center">
            <button type="submit" class="w3-button w3-green w3-section" name="upload_button">Upload</button>
            <button type="reset" class="w3-button w3-red w3-section">Reset</button>
          </div>
        </div>
      </form>
      <?php
      $tried_to_upload = false;
      ?>
    </div>
  </div>
</div>

<!-- add_admin modal -->
<div id="add_admin" class="w3-modal" <?php if ($tried_to_add_admin){ if ($error_exists){ echo "style=\"display:block;\""; } } ?>>
  <div class="w3-modal-content w3-animate-zoom">
    <div class="w3-container w3-white w3-center">
      <a onclick="document.getElementById('add_admin').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
      <h2 class="w3-wide">Add Admin</h2><hr/>
      <form action="" method="post">
        <div class="w3-section">
          <input class="w3-input w3-margin-bottom" required type="text" placeholder="Enter Username..." name="username" id="username" value="<?php if($tried_to_add_admin){echo $username; }?>">
          <?php
          if($tried_to_add_admin){
            if($username_error){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Username has to be between 6-100 characters long</p>
          </div>
          <?php
            }
          }
          ?>

          <input class="w3-input w3-margin-bottom" type="password" required placeholder="Enter Password..." name="password" id="password" value="<?php if($tried_to_add_admin){echo $password; }?>">
          <?php
          if($tried_to_add_admin){
            if($password_error){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Password has to be between 6-100 characters long</p>
          </div>
          <?php
            }
          }
          ?>

          <input class="w3-input w3-margin-bottom" type="password" required placeholder="Re-enter Password..." name="re_password" id="re_password" value="<?php if($tried_to_add_admin){echo $re_password; }?>" >
          <?php
          if($tried_to_add_admin){
            if($different_password){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Passwords don't match</p>
          </div>
          <?php
            }
          }
          ?>

          <div class="w3-center">
            <button type="submit" class="w3-button w3-green w3-section w3-margin-right" name="add_admin_button">Add</a>
            <button type="reset" class="w3-button w3-red w3-section">Reset</button>
          </div>
        </div>
      </form>
      <?php
      $tried_to_add_admin = false;
      ?>
    </div>
  </div>
</div>

<!-- add verse modal -->
<div id="add_verse" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('add_verse').style.display='none'" class="w3-display-topright w3-button w3-hover-red w3-hover-text-white w3-text-red w3-large">X</a>
        <h2 class="w3-wide">Add verse</h2><hr/>
        <form method="post" action="">
          <textarea class="w3-input w3-margin-bottom" required name="verse_text" id="verse_text" placeholder="verse text..."></textarea>
          <input class="w3-input" type="text" required placeholder="verse (book chapter:verse)" name="verse">
          <button type="submit" name="add_verse_button" class="w3-button w3-padding-large w3-green w3-margin-bottom">Add</button>
          <button type="reset" class="w3-button w3-padding-large w3-red w3-margin-bottom">Reset</button>
        </form>
      </div>
    </div>
</div>

<!-- add video modal -->
<!-- <div id="add_video" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('add_video').style.display='none'" class="w3-display-topright w3-button w3-red w3-large">X</a>
        <h2 class="w3-wide">Add video</h2><hr/>
        <form method="post" action="" enctype="multipart/form-data">
          <label for="file" class="w3-left">ቪድዮ ምረጽ</label>
          <input type="file" id="filename" name="filename" class="w3-input w3-margin-bottom" required />

          <?php
          if($tried_to_upload){
            if($unsupported_video_file){
          ?>
          <div class="w3-panel w3-red">
            <span onclick="this.parentElement.style.display='none'" class="w3-button w3-right">&times;</span>
            <p>Unsuported file type (supported - .mp4)</p>
          </div>
          <?php
            }
          }
          ?>
          <input class="w3-input" type="text" required placeholder="ኣርእስቲ..." name="title" value="<?php if($tried_to_add_admin){echo $title; }?>">

          <textarea class="w3-input w3-margin-bottom" required name="description" placeholder="መብርሂ..." ><?php if($tried_to_add_admin){echo $description; }?></textarea>
          
          <button type="submit" name="add_video_button" class="w3-button w3-padding-large w3-teal w3-margin-bottom">Upload</button>
          <button type="reset" class="w3-button w3-padding-large w3-red w3-margin-bottom">Reset</button>

        </form>
      </div>
    </div>
</div> -->

<!-- delete modal -->
<div id="delete_modal" style="<?php if($post_deleted){echo "display:block"; } ?>" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom w3-green">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('delete_modal').style.display='none'" class="w3-display-topright w3-button w3-red w3-large">X</a>
        <h2 class="w3-wide">Book Deleted Successfully</h2>
      </div>
    </div>
</div>
<?php } ?>
