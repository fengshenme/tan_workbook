package com.example.android_demo.j.netlunbotu;

public class ImageUri {
	private int imageId;
	private String text;
	private String imageUrl;
	
	public ImageUri(int imageId, String text) {
		super();
		this.imageId = imageId;
		this.text = text;
	}

	public final int getImageId() {
		return imageId;
	}

	public final void setImageId(int imageId) {
		this.imageId = imageId;
	}

	public final String getText() {
		return text;
	}

	public final void setText(String text) {
		this.text = text;
	}

	public String getImageUrl() {
		return imageUrl;
	}

	public void setImageUrl(String imageUrl) {
		this.imageUrl = imageUrl;
	}
}
