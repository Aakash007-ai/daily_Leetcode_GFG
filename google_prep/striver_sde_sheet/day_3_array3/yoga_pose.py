# Fixing the encoding issue by replacing non-latin characters like en-dashes with standard dashes
def safe_text(text):
    return text.replace("–", "-").replace("’", "'")

# Recreate PDF with fixed text encoding
pdf = PDF()
pdf.add_page()

# Updated sections with safe encoding
pdf.chapter_title("Overview")
pdf.chapter_body(safe_text("""
This document outlines a comprehensive strategy to build a monetizable yoga application featuring live classes, recorded sessions, and animated 3D demonstrations using open-source tools.
"""))

pdf.chapter_title("Tech Stack for Yoga App")
pdf.chapter_body(safe_text("""
Frontend (Web): React.js / Next.js
Frontend (Mobile): React Native / Flutter
Backend/API: Node.js / Django / Firebase
Video Hosting: YouTube (unlisted), Vimeo, or your own server
3D Animation Viewer: Three.js or Babylon.js
Animation Tools: Blender + MediaPipe/OpenPose
Payment Integration: Stripe / Razorpay (off-app)
"""))

pdf.chapter_title("Creating 3D Animations of Real Yoga")
pdf.chapter_body(safe_text("""
1. Record yourself (or a trainer) doing each yoga pose.
2. Use MediaPipe to extract skeleton/keypoints.
3. Import keypoints into Blender to animate a 3D rig.
4. Add voice-over instructions.
5. Export the animation as GLB/MP4 for use in your app.

Tools:
- MediaPipe: https://github.com/google/mediapipe
- Blender: https://www.blender.org/
- OpenPose (alternative): https://github.com/CMU-Perceptual-Computing-Lab/openpose
- Ready Player Me (avatars): https://readyplayer.me/
"""))

pdf.chapter_title("App Store Fees & Avoiding Commissions")
pdf.chapter_body(safe_text("""
Google Play Store takes 15% on first $1M in revenue.
Apple App Store takes 15-30% on digital goods.

To avoid this:
1. Use a Progressive Web App (PWA).
2. Sell subscriptions on your website using Stripe or Razorpay.
3. Use a hybrid model: free app, unlock premium features post-login.
4. WebView-based wrapper apps for stores.

References:
- Google Play Policy: https://support.google.com/googleplay/android-developer/answer/112622
- Apple App Store Guidelines: https://developer.apple.com/app-store/review/guidelines/
"""))

pdf.chapter_title("Recommended Workflow")
pdf.chapter_body(safe_text("""
1. Record yoga content with a smartphone.
2. Process videos with MediaPipe/OpenPose.
3. Animate with Blender and export GLB/MP4.
4. Render in Three.js for the web or React Native.
5. Accept payments via external Stripe or Razorpay page.
6. Distribute app as PWA or via WebView.

Examples:
- Three.js: https://threejs.org/
- Stripe: https://stripe.com/
- Razorpay: https://razorpay.com/
"""))

pdf.chapter_title("Next Steps")
pdf.chapter_body(safe_text("""
- Build MVP with React + Three.js
- Create yoga flows and animations
- Set up Stripe/Razorpay for monetization
- Use PWA or hybrid app strategy to minimize fees
"""))

# Save fixed PDF
pdf_file_path = "/mnt/data/Yoga_App_Strategy.pdf"
pdf.output(pdf_file_path)

# pdf_file_path
